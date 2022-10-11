#include <iostream>
#include <string>
#include <algorithm>

typedef long long int ll;

const ll MOD=ll(1e9)+7;

std::string str;
int n, m;

ll memo[2020][2020];
bool visit[2020][2020];

ll pd(int size, int op)
{
	//std::cout << "on pd(" << size << ',' << op << ")\n";
	if(op<0)
		return 0;
	if(size<=0)
		return op==0;
	
	ll &ans=memo[size][op];
	if(visit[size][op])
		return ans;
	visit[size][op]=true;
	ans=(pd(size-1,op-1) + pd(size-1,op+1))%MOD;
	//std::cout << "on pd(" << size << ',' << op << ") returning " << ans << "\n";
	return ans;
}

int main()
{
	std::cin >> n >> m >> str;
	int diff=0;
	int op=0;
	int close=0;
	for(int i=0;i<m;i++)
	{
		if(str[i]=='(')
			op++;
		else
			close++;
		diff=std::min(diff,op-close);
	}
	if(op>n/2 || close>n/2 || n&1)
	{
		std::cout << "0\n";
		return 0;
	}
	int limit=n-m-std::max(0,op-close);
	ll ans=0;
	//std::cout << "?\n";
	for(int i=-diff;i<=n-m;i++)
	{
		if(i==n-m)
		{
			if(str[m-1]=='(')
				break;
		}
		for(int j=-diff;j<=i;j++)
		{
			if(j-(i-j)<-diff)
				continue;
			int cur_op=(op+j);
			int cur_end=close+(i-j);
			int end_size=n-m-i;
			//end_size--;
			ll comb=pd(end_size,cur_op-cur_end);
			ll nxt=(pd(i,j-(i-j))*comb)%MOD;
			ans=(ans+nxt)%MOD;
			//std::cout << "found " << nxt << " on prefix size " << i << " using " << j << "'('\n";
			//std::cout << "left is " << pd(i,j-(i-j)) << ", right is " << comb << '\n';

		}
	}
	std::cout << ans << '\n';

}