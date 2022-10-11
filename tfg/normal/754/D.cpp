#include <cstdio> //fast io
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<ii, int> iii;

const int ms=400400;

int BIT[ms];

int n, k;

void upd(int x, int v)
{
	for(;x<ms;x+=x&-x)
		BIT[x]+=v;
}

int qry(int x)
{
	int ans=0;
	for(;x>0;x-=x&-x)
		ans+=BIT[x];
	return ans;
}

int qry(int l, int r)
{
	return qry(r)-qry(l-1);
}

iii a[ms];

std::priority_queue<ii> hp[2];

int ans=0;
int step=-1;
int cur_step=0;

void take()
{
	int on=hp[0].top().second;
	//std::cout << "taking " << on << "\n\n";
	hp[0].pop();
	upd(on,1);
	hp[1].push(ii(-a[on].first.second,on));
}

void rem()
{
	//std::cout << "removing " << hp[1].top().second << "\n";
	int total=qry(1,n);
	if(total<k)
	{
		upd(hp[1].top().second,-1);
		hp[1].pop();
		return;
	}

	int left=1, right=n+1;
	while(left!=right)
	{
		int mid=(left+right)/2;
		//std::cout << "(" << left << ", " << mid << ", " << right << ") = " << qry(mid,n) << "\n";
		if(total - qry(mid,n) < k)
			left=mid+1;
		else
			right=mid;
	}
	left--;
	int on=hp[1].top().second;
	//std::cout << "bsearch got " << left << '\n';
	//std::cout << "limits are (" << a[on].first.second << ", " << a[left].first.first << ")\n";
	int cur_ans=a[on].first.second-a[left].first.first+1;
	if(cur_ans>ans)
	{
		ans=cur_ans;
		step=cur_step;
	}
	hp[1].pop();
	upd(on,-1);
	//std::cout << "got ans " << cur_ans << "\n\n";
}

int main()
{
	
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int l, r;
		scanf("%i %i",&l,&r);
		a[i]=iii(ii(l,r),i);
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		hp[0].push(ii(-a[i].first.first,i));

	while(!hp[0].empty() || !hp[1].empty())
	{
		if(hp[1].empty())
			take();
		else if(hp[0].empty())
			rem();
		else if(hp[0].top()>=hp[1].top())
			take();
		else
			rem();
		cur_step++;
	}

	int get_step=step;

	cur_step=0;
	printf("%i\n",ans);
	if(ans==0)
	{
		for(int i=1;i<=k;i++)
		{
			if(i!=1)
				printf(" ");
			printf("%i",i);
		}
		printf("\n");
		return 0;
	}

	for(int i=1;i<=n;i++)
		hp[0].push(ii(-a[i].first.first,i));

	while(!hp[0].empty() || !hp[1].empty())
	{
		if(cur_step==get_step)
		{
			int got=0;
			for(int i=1;i<=n && got<k;i++)
			{
				if(qry(i,i))
				{
					if(got)
						printf(" ");
					printf("%i",a[i].second);
					got++;
				}
			}
		}
		if(hp[1].empty())
			take();
		else if(hp[0].empty())
			rem();
		else if(hp[0].top()>=hp[1].top())
			take();
		else
			rem();
		cur_step++;
	}
	printf("\n");

}