#include<bits/stdc++.h>

const int N = 200010;

int n;
char s[N];
std::queue <int> d, r;
std::set <int> set;

int main(){
	scanf("%d%s", &n, s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		if (s[i] == 'D'){
			d.push(i + 1);
		}
		else{
			r.push(i + 1);
		}
		set.insert(i + 1);
	}
	auto u = set.begin();
	while (!d.empty() && !r.empty()){
		if (d.front() == *u){
			set.erase(r.front());
			r.pop();
			d.push(d.front());
			d.pop();
		}
		else{
			set.erase(d.front());
			d.pop();
			r.push(r.front());
			r.pop();
		}
		++ u;
		if (u == set.end()){
			u = set.begin();
		}
	}
	if (d.empty()){
		return printf("R\n"), 0;
	}
	return printf("D\n"), 0;
}