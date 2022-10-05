#include <bits/stdc++.h>
using namespace std;
bool bib_start=false;
map<string,vector<string> > bib_part;
vector<string> cite;
int cnt=0;
bool cor=true;
string word_in_brk(string s){
	int lbrk=s.find_first_of('{'),rbrk=s.find_first_of('}');
	return s.substr(lbrk+1,rbrk-lbrk-1);
}
string after_rb(string s){
	return s.substr(s.find_first_of('}')+1,
	s.size()-s.find_first_of('}')-1);
}
int main(){
	string buf,kt;
	while(cin>>buf){
		if(bib_start==true&&buf[0]!='\\')	{
			bib_part[kt].push_back(buf);
		}
		if(buf[0]=='\\'){
			if(buf[1]=='b'&&buf[2]=='e')	bib_start=true;
			if(buf[1]=='e')	break;
			if(buf[1]=='b'&&buf[2]=='i'){
				if(cite[cnt]!=word_in_brk(buf))
					cor=false;
				cnt++;
				kt=word_in_brk(buf);
				bib_part[kt].push_back(after_rb(buf));
			}
			if(buf[1]=='c')	cite.push_back(word_in_brk(buf));
		}
	}
	if(cor){
		puts("Correct");
		exit(0);
	}
	puts("Incorrect");
	cout<<"\\begin{thebibliography}{99}\n";
	cnt=0;
	for(int i=0;i<cite.size();i++){
		cout<<"\\bibitem{"<<cite[i]<<"}";
		for(int j=0;j<bib_part[cite[i]].size();j++){
			if(j!=bib_part[cite[i]].size()-1)
				cout<<bib_part[cite[i]][j]<<" ";
			else	cout<<bib_part[cite[i]][j];
		}
		cout<<endl;
	}
	cout<<"\\end{thebibliography}";
}
/*
PaExusAP MffmnZK \cite{p}u xBU .teQbefF \cite{tyjek}Sn dcb LUiY WXk \cite{ypss}Mf,iS'AxILSdweUP \cite{dtrsm}QW b mqdMk \cite{yplof}ROV yV sXU,w FwFA u
\begin{thebibliography}{99}
\bibitem{yplof}hFs
\bibitem{p}WjH
\bibitem{dtrsm} rE w
\bibitem{tyjek}vKnnJ
\bibitem{ypss}xj
\end{thebibliography}
*/