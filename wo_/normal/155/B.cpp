#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

vector<P> cards;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int ina,inb;
		scanf("%d%d",&ina,&inb);
		cards.push_back(P(inb,ina));
	}
	sort(cards.begin(),cards.end());
	reverse(cards.begin(),cards.end());
	int cnt=1;
	int points=0;
	for(int i=0;i<n&&cnt>0;i++)
	{
		cnt--;
		cnt+=cards[i].first;
		points+=cards[i].second;
	}
	printf("%d\n",points);
	return 0;
}