#include<bits/stdc++.h>

struct poly{
	static const int N = 210;
	
	int a[N];
	
	poly (){memset(a, 0, sizeof(a));}
	
	int &operator[](int n){return a[n];}
	
	poly operator + (const poly &p)const{
		poly ret;
		for (int i = 0; i < N; ++ i){
			ret.a[i] = a[i] + p.a[i];
		}
		return ret;
	}
	
	poly operator - (const poly &p)const{
		poly ret;
		for (int i = 0; i < N; ++ i){
			ret.a[i] = a[i] - p.a[i];
		}
		return ret;
	}
	
	poly operator * (const poly &p)const{
		poly ret;
		for (int i = 0; i < N; ++ i){
			if (!a[i]) continue;
			for (int j = 0; j < N; ++ j){
				if (i + j >= N) break;
				ret.a[i + j] += a[i] * p.a[j];
			}
		}
		return ret;
	}
	
	bool check(){
		for (int i = 0; i < N; ++ i){
			if (std::abs(a[i]) > 1){
				return false;
			}
		}
		return true;
	}
	
	void write(){
		int len = N - 1;
		for ( ; len >= 0 && a[len] == 0; -- len);
		printf("%d\n", len);
		for (int i = 0; i <= len; ++ i){
			printf("%d%c", a[i], " \n"[i == len]);
		}
	}
};

const int N = 210;

poly ansa[N], ansb[N], coe[3];
int n;
bool flag;

void dfs(int now){
	if (now == n + 1){
		flag = true;
		return;
	}
	ansb[now] = ansa[now - 1];
	for (int i = 0; i < 3; ++ i){
		if (flag){
			return;
		}
		ansa[now] = ansa[now - 1] * coe[i];
		ansa[now] = ansa[now] + ansb[now - 1];
		if (ansa[now].check()){
			dfs(now + 1);
		}
		if (flag){
			return;
		}
		ansa[now] = ansa[now] - ansb[now - 1];
		ansa[now] = ansa[now] - ansb[now - 1];
		if (ansa[now].check()){
			dfs(now + 1);
		}
	}
}

int main(){
	scanf("%d", &n);
	ansa[0][0] = 1;
	coe[0][1] = coe[1][1] = coe[2][1] = 1;
	coe[0][0] = -1, coe[2][0] = 1;
	dfs(1);
	ansa[n].write();
	ansb[n].write();
	return 0;
}