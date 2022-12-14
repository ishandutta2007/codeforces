#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Student{
	int id;
	int a, b;
	int dif;
	Student(){}
	Student(int x, int y, int z){
		id = x;
		a = y;
		b = z;
		dif = b - a;
	}
};

bool cmp(const Student &s1, const Student &s2){
	return s1.dif < s2.dif;
}

Student students[3030];

int N;
int as[3030], bs[3030];

int dp1[3030][3030];
int dp2[3030][3030];

int p, s;
vector<int> pteam, steam;

void solve(){
	for(int i = 0; i < N; ++i){
		students[i] = Student(i, as[i], bs[i]);
	}
	sort(students, students + N, cmp);
	for(int i = 0; i < 3030; ++i){
		for(int j = 0; j < 3030; ++j){
			dp1[i][j] = -1;
			dp2[i][j] = -1;
		}
	}
	
	dp1[0][0] = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j <= i; ++j){
			if(dp1[i][j] == -1) continue;
			dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
			dp1[i + 1][j + 1] = max(dp1[i + 1][j + 1], dp1[i][j] + students[i].a);
		}
	}
	
	dp2[N][0] = 0;
	for(int i = N - 1; i >= 0; --i){
		for(int j = 0; j <= (N - 1 - i); ++j){
			if(dp2[i + 1][j] == -1) continue;
			dp2[i][j] = max(dp2[i + 1][j], dp2[i][j]);
			dp2[i][j + 1] = max(dp2[i][j + 1], dp2[i + 1][j] + students[i].b);
		}
	}
	
	int best_str = -1, best_div = -1;
	for(int i = 1; i < N; ++i){
		int val1 = dp1[i][p];
		int val2 = dp2[i][s];
		if(val1 < 0 || val2 < 0) continue;
		if(best_str < val1 + val2){
			best_str = val1 + val2;
			best_div = i;
		}
	}
	
	//dp1 restore
	int cur_c = p;
	for(int i = best_div; i >= 1; --i){
		if(cur_c > 0){
			if(dp1[i][cur_c] == dp1[i - 1][cur_c - 1] + students[i - 1].a){
				pteam.push_back(students[i - 1].id);
				cur_c--;
			}
		}
	}
	
	//dp2 restore
	cur_c = s;
	for(int i = best_div; i < N; ++i){
		if(cur_c > 0){
			if(dp2[i][cur_c] == dp2[i + 1][cur_c - 1] + students[i].b){
				steam.push_back(students[i].id);
				cur_c--;
			}
		}
	}
	
	printf("%d\n", best_str);
	for(int i = 0; i < pteam.size(); ++i){
		printf("%d%c", pteam[i] + 1, i + 1 == pteam.size() ? '\n' : ' ');
	}
	for(int i = 0; i < steam.size(); ++i){
		printf("%d%c", steam[i] + 1, i + 1 == steam.size() ? '\n' : ' ');
	}
}

void input(){
	scanf("%d%d%d", &N, &p, &s);
	for(int i = 0; i < N; ++i){
		scanf("%d", as + i);
	}
	for(int i = 0; i < N; ++i){
		scanf("%d", bs + i);
	}
}

int main(){
	input();
	solve();
	return 0;
}