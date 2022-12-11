const modp=1000000007;
var a,b,k,t,i,j,r:longint;
    f1,f2,pre1,pre2:array[-200507..200507] of int64;
	ans:int64;
begin
  readln(a,b,k,t);
  fillchar(f1,sizeof(f1),0);
  fillchar(f2,sizeof(f2),0);
  fillchar(pre1,sizeof(pre1),0);
  fillchar(pre2,sizeof(pre2),0);
  for i:=a to 200507 do
	pre1[i]:=1;
  for i:=b to 200507 do
	pre2[i]:=1;
  for i:=1 to t do
  begin
    for j:=a-k*t to 200507 do
	  f1[j]:=(f1[j-1]+pre1[j+k]+modp-pre1[j-k-1]) mod modp;
	for j:=b-k*t to 200507 do
	  f2[j]:=(f2[j-1]+pre2[j+k]+modp-pre2[j-k-1]) mod modp;
	pre1:=f1;
	pre2:=f2;
  end;
  ans:=0;
  for i:=a-k*t to a+k*t do
	ans:=(ans+int64(f2[i-1]*((f1[i]-f1[i-1]+modp) mod modp)) mod modp) mod modp;
  writeln(ans);
end.