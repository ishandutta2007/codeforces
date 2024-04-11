#include <vector>
#include <iostream>
#include <algorithm>

struct lazy_cont
{
    lazy_cont(){valid = false;}
    lazy_cont(int a){valid = true;num = a;}

    void apply_lazy(lazy_cont a)
    {
        if(!valid)
            *this = a;
        else if(a.valid)
            num = a.num;
    }

    bool valid;
    int num;
};

struct i_t
{
    i_t(){valid = lazy.valid = false;}
    i_t(int pos)
    {
        sum = low = high = l = r = pos;
        valid = true;
    }

    i_t(i_t a, i_t b)
    {
        if(!a.valid)
            *this = b;
        else if(!b.valid)
            *this = a;
        else
        {
            high = std::max(a.high, b.high);
            low = std::min(a.low, b.low);
            l = a.l;
            r = b.r;
            sum = a.sum + b.sum;
            valid = true;
        }
        reset_lazy();
    }

    lazy_cont lazy;

    void apply_lazy(lazy_cont a)
    {
        lazy.apply_lazy(a);
        if(a.valid)
        {
            high = low = lazy.num;
            sum = high;
            sum*= r - l + 1;
        }
    }
    void reset_lazy(){lazy = lazy_cont();}
    void print()
    {
        std::cout << "on (" << l << ", " << r << ") got " << high << ", " << low << ", " << sum << '\n';
    }

    bool valid;
    int l, r;
    int high, low;
    long long sum;
};

class Seg_Tree
{
public:
    Seg_Tree(int size)
    {
        n = size;
        st.resize(4*n);
        build(0, n - 1, 0);
    }

    long long getRange(int l, int r, int limit)
    {
        //std::cout << "getting range (" << l << ", " << r << ", " << limit << ")\n";
        //print();
        int from = lowerBound(0, n - 1, 0, limit + 1) - 1;
        //std::cout << "got bound on " << from << '\n';
        if(from < l)
            return 0;
        r = std::min(r, from);
        //print();
        long long ans = (long long) (r - l + 1) * limit;
        long long aux = qry(0, n - 1, l, r, 0).sum;
        update(0, n - 1, l, r, 0, limit);
        //print();
        //std::cout << "got " << ans - aux << ", " << ans << " - " << aux << '\n';
        return ans - aux;
    }

private:
    void print()
    {
        for(int i = 0; i < n; i++)
            std::cout << qry(0, n - 1, i, i, 0).high << " ";
        std::cout << '\n';
    }
    int left(int x){return x + x + 1;}
    int right(int x){return x + x + 2;}

    int n;
    std::vector<i_t> st;

    void push(int l, int r, int pos)
    {
        if(l != r)
        {
            st[left(pos)].apply_lazy(st[pos].lazy);
            st[right(pos)].apply_lazy(st[pos].lazy);
        }
        st[pos].reset_lazy();
    }

    int lowerBound(int l, int r, int pos, int k)
    {
        push(l, r, pos);

        if(l == r)
            return l;

        int mid = (l + r) / 2;
        if(st[left(pos)].high >= k)
            return lowerBound(l, mid, left(pos), k);
        else
            return lowerBound(mid + 1, r, right(pos), k);
    }

    void build(int l, int r, int pos)
    {
        if(l == r)
        {
            st[pos] = i_t(l);
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, left(pos));
        build(mid + 1, r, right(pos));
        st[pos] = i_t(st[left(pos)], st[right(pos)]);
    }

    void update(int l, int r, int i, int j, int pos, int num)
    {
        push(l, r, pos);
        if(l >= i && r <= j)
        {
            st[pos].apply_lazy(lazy_cont(num));
            //std::cout << "updating (" << l << ", " << r << ") with " << num << '\n';
        }
        else if(r < i || l > j)
            return;
        else
        {
            int mid = (l + r) / 2;
            update(l, mid, i, j, left(pos), num);
            update(mid + 1, r, i, j, right(pos), num);
            st[pos] = i_t(st[left(pos)], st[right(pos)]);
        }
    }
    i_t qry(int l, int r, int i, int j, int pos)
    {
        push(l, r, pos);
        if(l >= i && r <= j)
            return st[pos];
        else if(r < i || l > j)
            return i_t();

        int mid = (l + r) / 2;
        i_t ret = i_t(qry(l, mid, i, j, left(pos)), qry(mid + 1, r, i, j, right(pos)));
        //std::cout << "on real (" << l << ", " << r << "): ";ret.print();
        return ret;
    }
};

const int ms = 200200;

std::vector<int> divs[ms];
std::vector<int> where[ms];

int a[ms];
int n;

long long solve(int i, int j, long long gcd, Seg_Tree &tree)
{
    //std::cout << "solving (" << i << ", " << j << ", " << gcd << ")\n";
    long long count = 0;
    if(j - i > 1)
        count += tree.getRange(i + 1, j - 1, j);
    if(i > 1)
        count += tree.getRange(1, i - 1, i);
    if(j < n)
        count += tree.getRange(j + 1, n, n + 1);
    return count * gcd;
}

int main()
{
    for(int i = 1; i < ms; i++)
        for(int j = i; j < ms; j += i)
            divs[j].push_back(i);
     std::cin >> n;
    for(int i = 1; i <= n; i++)
        std::cin >> a[i];

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < divs[a[i]].size(); j++)
            where[divs[a[i]][j]].push_back(i);

    Seg_Tree tree(n + 2);

    long long ans = 0;
    for(int i = ms - 1; i > 0; i--)
    {
        if(where[i].size() <= 1)
            continue;
        ans += solve(where[i][0], where[i].back(), i, tree);
        if(where[i].size() > 2)
        {
            ans += solve(where[i][0], where[i][1], i, tree);
            ans += solve(where[i][where[i].size() - 2], where[i][where[i].size() - 1], i, tree);
        }
    }

    std::cout << ans << '\n';
}