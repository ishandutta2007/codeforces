#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, x, y, z, id, m;
struct node
{
    node * s[2];
    int col, l, r;
    long long sum, dlt;
    node(int l, int r) : l(l), r(r)
    {
        dlt = 0;
        if(l == r)
        {
            col = l;
            sum = 0;
        }else
        {
            s[0] = new node(l, (l + r) / 2);
            s[1] = new node((l + r) / 2 + 1, r);
            sum = 0;
            col = -1;
        }
    }
    void down()
    {
        if(!dlt or col == -1) return;
        for(int d = 0; d < 2; d++)
        {
            s[d]->dlt += dlt;
            s[d]->col = col;
            s[d]->sum += (long long)(s[d]->r - s[d]->l + 1) * dlt;
        }
        dlt = 0;
    }
    void paint()
    {
        if(l > y or r < x) return;
        else if(x <= l and r <= y)
        {
            if(col == -1)
            {
                s[0]->paint(), s[1]->paint();
                sum = s[0]->sum + s[1]->sum;
                col = z;
                dlt = 0;
            }
            else
            {
                sum += (long long)(r - l + 1) * abs(z - col);
                dlt += abs(z - col);
                col = z;
                
            }
        }else
        {
            down();
            s[0]->paint(), s[1]->paint();
            sum = s[0]->sum + s[1]->sum;
            col = -1;
        }
    }
    long long getsum()
    {
        if(l > y or r < x) return 0;
        else if(x <= l and r <= y) return sum;
        else {down(); return s[0]->getsum() + s[1]->getsum();}
    }
} * root;

int main()
{
    scanf("%d%d", &n, &m);
    root = new node(1, n);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &id);
        if(id == 1)
        {
            scanf("%d%d%d", &x, &y, &z);
            root->paint();
        }else
        {
            scanf("%d%d", &x, &y);
            printf("%I64d\n", root->getsum());
        }
    }
    fclose(stdin);
    return 0;
}