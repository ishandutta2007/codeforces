#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, c, last=-1;
vector<int> V;
bool B[200005];
int A[200005];
PII L[200005];
set<int> S;
set<int>::iterator it;

void add(int val)
{
  if(A[val]!=0)
  {
    A[val]++;
    return;
  }
  A[val]=1;
  S.insert(-val);
  if(last!=-1)
    L[last].S=val;
  L[val].F=last;
  last=val;
}

bool make(int x)
{
  if(x==0)
    return true;
  //printf("lol %d\n", x);
  it=S.lower_bound(-x);
  if(it==S.end())
    return false;
  int tmp=-(*it), am=min(x/tmp, A[tmp]);
  //printf("tmp, am: %d %d\n", tmp, am);
  x-=am*tmp;
  while(x!=0 && L[tmp].F!=-1 && x>=L[tmp].F)
  {
    tmp=L[tmp].F;
    am=min(x/tmp, A[tmp]);
    x-=am*tmp;
  }
  if(x==0)
    return true;
  if(L[tmp].F==-1)
    return false;
  return make(x);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &c, &n);
	for(int i=0; i<=c; i++)
	  L[i]=MP(-1, -1);
	for(int i=0; i<n; i++)
	{
	  int a;
	  scanf("%d", &a);
	  V.PB(a);
	}
	sort(V.begin(), V.end());
	int tmp=c;
	for(int i=n-1; i>=0; i--)
	{
	  if(V[i]<=tmp)
	  {
	    tmp-=V[i];
	    B[i]=1;
	  }
	}
	tmp=0;
	int todo=0;
	for(int i=1; i<c; i++)
	{
	 // printf("i=%d\n", i);
	  while(V[tmp]<=i && tmp<n)
	  {
	    add(V[tmp]);
	   // printf("add %d\n", V[tmp]);
	    if(B[tmp])
	      todo+=V[tmp];
	    tmp++;
	  }
	 // printf("todo=%d\n", todo);
	  if(todo<i)
	    continue;
	  if(!make(todo-i))
	  {
	    printf("%d\n", i);
	    return 0;
	  }
	}
	printf("Greed is good\n");
	return 0;
}