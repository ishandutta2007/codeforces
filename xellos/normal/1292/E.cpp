#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const char C[] = ".CHO";
char b[64];

void finish(int l, int r, int N, bool skip_eq = false) {
	while(l || r != N) {
		if(r != N && b[r]) {r++; continue;}
		if(l && b[l-1]) {l--; continue;}
		int n = 3 - skip_eq;
		for(int k = 1; k <= 3; k++) {
			if(skip_eq && k == b[(r != N) ? r-1 : l]) continue;
			n--;
			if(n == 0) {
				if(r != N) b[r++] = k;
				else b[--l] = k;
				break;
			}
			string qs;
			for(int i = l; i < r; i++) qs += C[b[i]];
			if(r != N) qs += C[k];
			else qs.insert(begin(qs), C[k]);
			cout << "? " << qs << endl;
			int K;
			cin >> K;
			if(K == -1) exit(0);
			bool ok = false;
			for(int i = 0, a; i < K; i++) {
				cin >> a;
				if(a-1 == ((r != N) ? l : (l-1))) ok = true;
			}
			if(!ok) continue;
			if(r != N) b[r++] = k;
			else b[--l] = k;
			break;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N;
		memset(b, 0, sizeof(b));
		if(N == 4) {
			cout << "? " << C[1] << C[2] << endl;
			cin >> K;
			if(K == -1) exit(0);
			for(int i = 0, a; i < K; i++) {
				cin >> a;
				b[a-1] = 1, b[a] = 2;
			}
			cout << "? " << C[1] << C[3] << endl;
			cin >> K;
			if(K == -1) exit(0);
			for(int i = 0, a; i < K; i++) {
				cin >> a;
				b[a-1] = 1, b[a] = 3;
			}
			cout << "? " << C[2] << C[1] << endl;
			cin >> K;
			if(K == -1) exit(0);
			for(int i = 0, a; i < K; i++) {
				cin >> a;
				b[a-1] = 2, b[a] = 1;
			}
			cout << "? " << C[2] << C[3] << endl;
			cin >> K;
			if(K == -1) exit(0);
			for(int i = 0, a; i < K; i++) {
				cin >> a;
				b[a-1] = 2, b[a] = 3;
			}
			int l = 0;
			while(!b[l] && l != 4) l++;
			if(l < 4) finish(l, l+2, N);
			else {
				cout << "? " << C[1] << C[1] << C[1] << endl;
				cin >> K;
				if(K == -1) exit(0);
				for(int i = 0, a; i < K; i++) {
					cin >> a;
					b[a-1] = b[a] = b[a+1] = 1;
				}
				cout << "? " << C[2] << C[2] << C[2] << endl;
				cin >> K;
				if(K == -1) exit(0);
				for(int i = 0, a; i < K; i++) {
					cin >> a;
					b[a-1] = b[a] = b[a+1] = 2;
				}
				cout << "? " << C[3] << C[3] << C[3] << endl;
				cin >> K;
				if(K == -1) exit(0);
				for(int i = 0, a; i < K; i++) {
					cin >> a;
					b[a-1] = b[a] = b[a+1] = 3;
				}
				l = 0;
				while(!b[l] && l != 4) l++;
				if(l < 4) finish(l, l+3, N, true);
				else {
					b[0] = b[1] = 3;
					cout << "? " << C[3] << C[3] << C[1] << C[1] << endl;
					int a;
					cin >> K;
					if(K == -1) exit(0);
					if(K) cin >> a;
					if(K) b[2] = b[3] = 1;
					else b[2] = b[3] = 2;
				}
			}
			string ans;
			for(int i = 0; i < N; i++) ans += C[b[i]];
			cout << "! " << ans << endl;
			cin >> N;
			if(N == -1) exit(0);
			continue;
		}
		cout << "? " << C[1] << C[1] << endl;
		cin >> K;
		if(K == -1) exit(0);
		if(K) {
			for(int i = 0, a; i < K; i++) {
				cin >> a;
				b[a-1] = b[a] = 1;
			}
			int l = 0;
			while(!b[l]) l++;
			finish(l, l+2, N);
		}
		else {
			bool found = false;
			for(int k = 0; k < 4; k++) {
				cout << "? " << C[2+(k&1)] << C[1] << C[2+(k>>1)] << endl;
				cin >> K;
				if(K == -1) exit(0);
				if(K == 0) continue;
				found = true;
				for(int i = 0, a; i < K; i++) {
					cin >> a;
					b[a-1] = 2+(k&1);
					b[a] = 1;
					b[a+1] = 2+(k>>1);
				}
				int l = 0;
				while(!b[l]) l++;
				finish(l, l+3, N);
				break;
			}
			if(!found) {
				for(int k = 2; k <= 3; k++) {
					cout << "? " << C[k] << C[k] << endl;
					cin >> K;
					if(K == -1) exit(0);
					if(K) found = true;
					for(int i = 0, a; i < K; i++) {
						cin >> a;
						b[a-1] = b[a] = k;
					}
				}
				if(found) {
					for(int i = 2; i <= N-2; i++) if(!b[i] && b[i-1])
						b[i] = (b[i-1] == 2) ? 3 : 2;
					for(int i = N-3; i > 0; i--) if(!b[i] && b[i+1])
						b[i] = (b[i+1] == 2) ? 3 : 2;
					finish(1, N-1, N, true);
				}
				else {
					for(int k = 0; k <= 1; k++) {
						cout << "? " << C[2+k] << C[3-k] << C[2+k] << C[3-k] << endl;
						cin >> K;
						if(K == -1) exit(0);
						if(K) found = true;
						for(int i = 0, a; i < K; i++) {
							cin >> a;
							b[a-1] = b[a+1] = 2+k;
							b[a] = b[a+2] = 3-k;
						}
					}
					if(!found) {
						b[0] = b[N-1] = 1;
						string s;
						s += C[1];
						for(int i = 0; i < N-2; i++) s += C[2+(i%2)];
						s += C[1];
						cout << "? " << s << endl;
						cin >> K;
						if(K == -1) exit(0);
						if(K) {
							cin >> K;
							if(K == -1) exit(0);
							for(int i = 0; i < N-2; i++) b[i+1] = 2+(i%2);
						}
						else for(int i = 0; i < N-2; i++) b[i+1] = 3-(i%2);
					}
					else {
						for(int i = 0; i < N; i++) if(b[i]) {
							for(int j = i+1; j < N-1; j++) b[j] = b[j-1]^1;
							for(int j = i-1; j > 0; j--) b[j] = b[j+1]^1;
							break;
						}
						finish(1, N-1, N, true);
					}
				}
			}
		}
		string ans;
		for(int i = 0; i < N; i++) ans += C[b[i]];
		cout << "! " << ans << endl;
		cin >> N;
		if(N == -1) exit(0);
	}
}