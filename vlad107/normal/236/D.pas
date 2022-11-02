{$r+,q+,s+,i+,o-}
var
  ssq,sf,st,ss:extended;
  f,p:array[0..500500]of extended;
  n,i:longint;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=2 to n+1 do read(p[i]);
  inc(n,2);
  p[1]:=0;p[n]:=0;
  ssq:=0;sf:=0;st:=0;ss:=0;
  for i:=1 to n do begin
    f[i]:=sf+ss*(i-1)*(i-1)+ssq-st*2*(i-1);
    f[i]:=f[i]*(1-p[i]);
    sf:=sf*p[i]+f[i];
    ss:=ss*p[i]+1-p[i];
    st:=st*p[i]+(1-p[i])*i;
    ssq:=ssq*p[i]+(1-p[i])*i*i;
  end;
  writeln(f[n]:0:10);
end.