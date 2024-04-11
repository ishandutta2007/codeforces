import std.stdio;
import std.string;
import std.algorithm;

void main() {
	string S =chomp(readln());
	int N =S.length;
	int poc[];
	long pos[];
	poc.length =pos.length =N+1;
	pos[0] =1, poc[0] =0;
	
	for(int i =0; i < N; i++) {
		int a =poc[i], b =0, c =0, j =i;
		while(true) {
			c +=cast(int)(S[j]-'0');
			if(c >= 9 || j == 0) break;
			j--;}
		b =poc[j];
		if(c == 9 && j == i-1) b++;
		poc[i+1] =max(a,b);
		pos[i+1] =0;
		if(poc[i+1] == a) pos[i+1] +=pos[i];
		if(poc[i+1] == b && b > poc[j]) pos[i+1] +=pos[j];}
//		writeln(pos[i]," ",poc[i]);}
	
	writeln(pos[N]);}