#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int sum = 0, mx = 0;
    node *left = nullptr, *right = nullptr;
    
    node *getLeft()
    {
	if(left == nullptr) left = new node;
	return left;
    }
    
    node *getRight()
    {
	if(right == nullptr) right = new node;
	return right;
    }
    
    void setValue(int k, int v, int a = 0, int b = 1 << 30)
    {
	if(b == a + 1)
	    mx = sum = v;
	else if(k < (a + b) / 2)
	{
	    getLeft()->setValue(k, v, a, (a + b) / 2);
	    mx = ::max(mx, left->mx + sum);
	}
	else
	{
	    getRight()->setValue(k, v, (a + b) / 2, b);
	    mx = ::max(mx, right->mx + sum);
	}
    }
    
    void insert(int pa, int pb, int a = 0, int b = 1 << 30)
    {
	if(a >= pb || b <= pa) return;
	if(a >= pa && b <= pb)
	{
	    sum++;
	    mx++;
	}
	else
	{
	    mx = 0;
	    if(left)
	    {
		left->insert(pa, pb, a, (a + b) / 2);
		mx = ::max(mx, left->mx);
	    }
	    if(right)
	    {
		right->insert(pa, pb, (a + b) / 2, b);
		mx = ::max(mx, right->mx);
	    }
	    mx += sum;
	}
    }
    
    int max(int pa, int pb, int a = 0, int b = 1 << 30)
    {
	if(a >= pb || b <= pa) return 0;
	if(a >= pa && b <= pb) return mx;
	int ans = 0;
	if(left) ans = ::max(ans, left->max(pa, pb, a, (a + b) / 2));
	if(right) ans = ::max(ans, right->max(pa, pb, (a + b) / 2, b));
	return ans + sum;
    }
};

int main()
{
    int n, r, h, t;
    node *tree = new node;
    priority_queue<pair<int, int> > pq;
    scanf("%d %d", &n, &r);
    for(int i = 0; i < n; i++)
    {
	scanf("%d %d", &h, &t);
	if(t < 0) continue;
	h = max(h, 0);
	pq.push(make_pair(-t, -h));
	pq.push(make_pair(-h, 2));
	//pq.push(make_pair(-(t + 1), 2));
    }
    int prev = -1;
    while(!pq.empty())
    {
	int a = -pq.top().second, b = -pq.top().first;
	pq.pop();
	if(a < 0)
	{
	    if(b == prev) continue;
	    int v = tree->max(0, b - r + 1);
	    if(a == -2 || v > tree->max(prev, prev + 1))
	    {
		tree->setValue(b, v);
		prev = b;
		if(b + r <= 1000000000)
		    pq.push(make_pair(-(b + r), 1));
	    }
	}
	else tree->insert(a, b + 1);
	if(tree->mx > n) puts("wtf");
    }
    printf("%d\n", tree->mx);
}