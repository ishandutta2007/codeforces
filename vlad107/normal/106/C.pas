{$r-,q-,s-,i-,o+}
var
  n,m,i,j,cc,dd,k:longint;
  kq,c,d,f:array[0..500500]of longint;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m,c[0],d[0]);
  kq[0]:=n div c[0]+1;
  fillchar(f,sizeof(f),$FF);
  for i:=1 to m do begin
    read(cc,dd,c[i],d[i]);
    kq[i]:=cc div dd;
  end;
  f[0]:=0;
  for i:=0 to m do 
    for j:=n downto 0 do 
      for k:=1 to kq[i] do 
        if (f[j]>=0)and(j+c[i]*k<=n)and(f[j]+d[i]*k>f[j+c[i]*k])then f[j+c[i]*k]:=f[j]+d[i]*k;
  j:=0;
  for i:=1 to n do 
    if (f[i]>j)then j:=f[i];
  writeln(j);
end.