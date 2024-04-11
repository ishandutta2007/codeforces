#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;
typedef pair<vector<PLL>, PLL> PVP;
map<PLL, int> mp;

const int MAXN = 1e5 + 10;
PVP E[MAXN];
PLL F[MAXN], G[MAXN];
char s[100];

ll Calc(char ch){
	if (ch == '/')
		return 29;
	if (ch == '#')
		return 27;
	if (ch == '.')
		return 28;
	return (ch - 'a' + 1);
}

char Anti_Calc(long long x){
	if (x == 0)
		return 0;
	if (x == 29)
		return '/';
	if (x == 27)
		return 0;
	if (x == 28)
		return '.';
	return ('a' + x - 1);
}

PLL work(int p, int q){
	ll x = 1, y = 1;
	for(int i = 0; i < 11; i++)
		x = (x << 5) + Calc((p + i <= q) ? s[p + i] : '#');
	for(int i = 11; i < 22; i++)
		y = (y << 5) + Calc((p + i <= q) ? s[p + i] : '#');
	return PLL(x, y);
}

char t[100];

void Pit(PLL p){
	ll x = p.first, y = p.second;
	printf("http://");
	for(int i = 10; i >= 0; i--){
		t[i] = Anti_Calc(x & 31);
		x >>= 5;
	}
	for(int i = 21; i >= 11; i--){
		t[i] = Anti_Calc(y & 31);
		y >>= 5;
	}
	t[22] = 0;
	printf("%s", t);
}

int main(){
	int n;
	cin>>n;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		int l = strlen(s);
		int p, q;
		for(p = 7; p < l && s[p] != '/'; p++);
		PLL Nico = work(7, p-1);
	//	for(int i = 7; i <= p - 1; i ++)
	//		putchar(s[i]); puts("");
	//	cout<<hex<<Nico.first<<' '<<hex<<Nico.second<<endl;
		PLL Maki = work(p, l-1);
		if (mp.find(Nico) != mp.end()){
			E[mp[Nico]].first.push_back(Maki);
		}
		else{
			mp[Nico] = ++cnt;
			E[cnt].second = Nico; 
			E[cnt].first.push_back(Maki);
		}
	}
/*	for(int i = 1; i <= cnt; i++){
		cout<<"###################"<<endl; 
		cout<<hex<<E[i].second.first<<' '<<hex<<E[i].second.second<<endl;
		for(int j = 0; j < E[i].first.size(); j++)
			cout<<"    "<<hex<<E[i].first[j].first<<' '<<hex<<E[i].first[j].second<<endl;
	}*/
	for(int i = 1; i <= cnt; i++){
		sort(E[i].first.begin(), E[i].first.end());
		E[i].first.erase(unique(E[i].first.begin(), E[i].first.end()), E[i].first.end());	
	}
/*	puts("\n");
	for(int i = 1; i <= cnt; i++){
		cout<<"###################"<<endl; 
		cout<<hex<<E[i].second.first<<' '<<hex<<E[i].second.second<<endl;
		for(int j = 0; j < E[i].first.size(); j++)
			cout<<"    "<<hex<<E[i].first[j].first<<' '<<hex<<E[i].first[j].second<<endl;
	}*/
	sort(E + 1, E + cnt + 1);
/*	puts("\n");
	for(int i = 1; i <= cnt; i++){
		cout<<"###################"<<endl; 
		cout<<hex<<E[i].second.first<<' '<<hex<<E[i].second.second<<endl;
		for(int j = 0; j < E[i].first.size(); j++)
			cout<<"    "<<hex<<E[i].first[j].first<<' '<<hex<<E[i].first[j].second<<endl;
	}*/
	int ans = 0, now = 1;
	for(int i = 2; i <= cnt + 1; i++){
		if (E[i].first == E[now].first){
		
		}
		else{
			if (i - now > 1){
				F[++ans] = PLL(now, i-1);
			}
			now = i;
		}
	}
	cout<<ans<<endl;
	for(int i = 1; i <= ans; i++){
		//cout<<F[i].first<<' '<<F[i].second<<endl;
		for(int j = F[i].first; j <= F[i].second; j++){
		//for(int j = 0; j < F[i].size(); j++){
			Pit(E[j].second);
			printf("%c", " \n"[j == F[i].second]);
		}
	}
	return 0;
}