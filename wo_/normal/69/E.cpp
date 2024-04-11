#include<cstdio>
#include<set>
#include<map>

using namespace std;

const int fail=1000000007;

set<int,greater<int> > one;
map<int,int> many;

int get()
{
	if(one.empty()) return fail;
	return *one.begin();
}

void add(int x)
{
	if(one.count(x)>0)
	{
		one.erase(x);
	}
	else
	{
		if(many[x]==0) one.insert(x);
	}
	many[x]++;
}

void del(int x)
{
	if(one.count(x)>0)
	{
		one.erase(x);
	}
	else
	{
		if(many[x]==2)
		{
			one.insert(x);
		}
	}
	many[x]--;
}

void print()
{
	int ans=get();
	if(ans==fail) printf("Nothing\n");
	else printf("%d\n",ans);
}

int a[100100];

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<K;i++) add(a[i]);
	for(int i=K;i<N;i++)
	{
		print();
		add(a[i]);
		del(a[i-K]);
	}
	print();
	return 0;
}