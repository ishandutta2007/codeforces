#include<stdio.h>
#include<vector>
using namespace std;
vector<int> map[200];
int v[200], k[200];
int get(int x){
	int t;
	if(v[x]) return k[x];
	v[x] = true;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", k+x);
	for(int i=1; i<=k[x]; i++)
	{
		scanf("%d", &t);
		map[x].push_back(t);
	}
	return k[x];
}
int next(int x){
	get(x);
	int t = map[x].back();
	map[x].pop_back();
	while(v[t]){
		t = map[x].back();
		map[x].pop_back();
	}
	return t;
}
void solve(){
	int h;
	scanf("%d", &h);
	vector<int> l1, l2;
	int x=1, nh=-1;
	for(int i=1; i<(1<<h); i++){
		map[i].clear();
		k[i] = v[i] = 0;
	}
	int k;
	for(; ;){
		l1.push_back(x);
		k = get(x);
		if(k==2){
			printf("! %d\n", x);
			fflush(stdout);
			return;
		}
		if(k==1){
			break;
		}
		x = next(x);
	}
	if(x==1){
		x = next(x);
		nh = h-2;
	}
	else{
		for(x=1; ;){
			l2.push_back(x);
			k = get(x);
			if(k==2){
				printf("! %d\n", x);
				fflush(stdout);
				return;
			}
			if(k==1){
				break;
			}
			x = next(x);
		}

		if(l1.size() == l2.size())
		{
			nh = h-l1.size()-1;
			x = 1;
		} else if(l1.size() > l2.size()){
			nh = h - (l1.size()+l2.size())/2-1;
			x = l1[(l1.size() - l2.size())/2];
		} else{
			nh = h - (l1.size()+l2.size())/2-1;
			x = l2[(l2.size() - l1.size())/2];
		}
		x = next(x);
	}

	l1.clear(); l2.clear();
	for(; nh > 2;){
		int d;
		l1.clear();
		for(d=0;;d++){
			l1.push_back(x);
			k = get(x);
			if(k==2){
				printf("! %d\n", x); fflush(stdout); return;
			}
			if(k==1) break;
			x = next(x);
		}
		int dd = (1+d+(h-nh))/2;
		x = l1[(1+d-(h-nh))/2];
		nh = h-dd-1;
		x=next(x);
	}
	if(nh == 0){
		printf("! %d\n", x);
		fflush(stdout);
		return;
	}
	if(nh == 1){
		get(x);
		int xx = next(x);
		int kk = get(xx);
		if(kk == 2) printf("! %d\n", xx);
		else printf("! %d\n", next(x));
		fflush(stdout);
		return;
	}
	get(x);
	int xx = next(x);
	if(get(xx) != 1){

		int t = next(xx);
		if(get(t) == 2)
		{
			printf("! %d\n", t);
			fflush(stdout);
			return;
		}
		t = next(xx);
		if(get(t) == 2)
		{
			printf("! %d\n", t);
			fflush(stdout);
			return;
		}
	}

	xx = next(x);
	get(xx);
	int t = next(xx);
	if(get(t) == 2) printf("! %d\n", t);
	else printf("! %d\n", next(xx));
	fflush(stdout);
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int T=1; T<=t; T++){
		solve();
	}
	return 0;
}