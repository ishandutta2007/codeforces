#include <stdio.h>
#include <queue>
using namespace std;
const int N=200050;
queue<int> q;
int cnt[N],past[N],a[N];
bool skipped[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),cnt[a[i]]++;
	for(i=1;i<=n;i++) if(cnt[i]==0) q.push(i);
	for(i=1;i<=n;i++) past[i]=cnt[i];
	printf("%i\n",q.size());
	for(i=1;i<=n;i++)
	{
		if(past[a[i]]>1)
		{
			cnt[a[i]]--;
			if(!skipped[a[i]] && cnt[a[i]]==0){ a[i]=a[i];}
			else if(!q.empty() && (a[i]>q.front() || skipped[a[i]]))
			{
				a[i]=q.front();
				q.pop();
			}
			else skipped[a[i]]=true;
		}
		printf("%i ",a[i]);
	}
	printf("\n");
	return 0;
}