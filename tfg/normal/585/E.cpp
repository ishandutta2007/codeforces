#include <cstdio>
#include <vector>
#include <utility>

typedef long long ll;
typedef std::pair<int, int> ii;

const int mn=int(1e7)+2;
const int ms=5*100000+2;

int group[mn];
int smallest_p[mn];
int freq[mn];
int divs[mn];
int combs[mn];
std::vector<int> primes;
std::vector<ii> group_v;

ll powers[ms];
const ll MOD=ll(1e9)+7;

void fill(int ind, int cur, int val, int taken)
{
	if(ind==primes.size())
	{
		if(!taken) return;
		//printf("filling with %i on %i\n",((taken&1)?1:-1)*val,cur);
		combs[cur]+=((taken&1)?1:-1)*val;
		//freq[cur]+=val;
		return;
	}
	fill(ind+1,cur*primes[ind],val,taken+1);
	fill(ind+1,cur,val,taken);
}

ll take(int ind, int cur, int taken)
{
	ll ans=0;
	if(ind==primes.size())
	{
		if(!taken) return 0;
		if(!(taken&1))
		{
			ans=-(powers[-combs[cur]]-1);
		}
		else
		{
			ans=powers[combs[cur]]-1;
		}
		//printf("taking with %lli on %i, combs is %i\n",ans,cur,divs[cur]);
		ans=(ans+MOD)%MOD;
	}
	else
	{
		ans=take(ind+1,cur*primes[ind],taken+1);
		ans=(ans+take(ind+1,cur,taken))%MOD;
	}
	return ans;	
}

int a[ms];

int n;
ll total=0;





int get_smallest(int x)
{
	if(smallest_p[x]) return smallest_p[x];
	return x;
}

int get_group(int x)
{
	if(group[x]) return group[x];
	if(smallest_p[x]==0) return group[x]=x;
	if((x/smallest_p[x])%smallest_p[x]==0) return group[x]=get_group(x/smallest_p[x]);
	return group[x]=smallest_p[x]*get_group(x/smallest_p[x]);
}

int get_size(int x)
{
	if(freq[x]) return freq[x];
	if(x/get_smallest(x)==1) return freq[x]=1;
	return freq[x]=1+get_size(x/get_smallest(x));
}

int main()
{
	powers[0]=1;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
		powers[i]=(powers[i-1]*2)%MOD;
	for(int i=0;i<n;i++)
		scanf("%i",a+i);
	group[1]=1;
	for(int i=2;i*i<mn;i++)
	{
		if(smallest_p[i]) continue;
		group[i]=i;
		for(int j=i*i;j<mn;j+=i)
		{
			if(!smallest_p[j])
			{
				smallest_p[j]=i;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!freq[get_group(a[i])])
			group_v.push_back(ii(get_group(a[i]),0));
		freq[get_group(a[i])]++;
		//printf("adding from %i to %i, smallest %i\n",a[i],get_group(a[i]),get_smallest(a[i]));
	}
	for(int i=0;i<group_v.size();i++)
	{
		group_v[i].second=freq[group_v[i].first];
		freq[group_v[i].first]=0;
	}
	ll ans=0;
	for(int i=0;i<group_v.size();i++)
	{
		primes.clear();
		int cur=group_v[i].first;
		//printf("starting filling on %i\n",cur);
		while(cur!=1)
		{
			primes.push_back(get_smallest(cur));
			cur/=get_smallest(cur);
		}
		fill(0,1,group_v[i].second,0);
	}
	total=0;
	//printf("first total is %lli\n",total);
	for(int i=2;i<mn;i++)
	{
		if(!combs[i]) continue;
		if(combs[i]>0)
			total=(total+powers[combs[i]]-1+MOD)%MOD;
		else
			total=(total-(powers[-combs[i]]-1)+MOD)%MOD;
		
		ll cur=combs[i];
		//printf("going through multiples of %i, %lli combs\n",i,cur);
		/*for(int j=i;j<mn;j+=i)
		{
			divs[j]=(int)(((ll)divs[j]+cur+MOD)%MOD);
		}*/
		//printf("there are %i with %i and %i on the intersection\n",divs[i],i,freq[i]);
		
	}
	divs[1]=1;
	for(int i=0;i<group_v.size();i++)
	{
		//printf("starting to count on %i\n",group_v[i].first);
		primes.clear();
		int cur=group_v[i].first;
		while(cur!=1)
		{
			primes.push_back(get_smallest(cur));
			cur/=get_smallest(cur);
		}
		ll next=total;
		ll taking=0;
		taking=(taking + take(0,1,0))%MOD;
		//printf("got %lli and taking %lli on %i, there are %i divs.\n",next,taking,group_v[i].first,divs[group_v[i].first]);
		next=(next-taking+MOD)%MOD;
		next=((ll)group_v[i].second*next)%MOD;
		
		
		ans=(ans+next)%MOD;
		//printf("next is %lli, ans is %lli, freq is %i\n",next,ans,group_v[i].second);
	}
	printf("%lli\n",ans);
}