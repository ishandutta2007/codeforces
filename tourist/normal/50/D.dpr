{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  cur,x0,y0,need,n,k,i,it,j: longint;
  prob,g,f,d: array [0..1010] of extended;
  x,y: array [0..1010] of longint;
  sum,ll,rr,mid,ans: extended;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,k,need,x0,y0);
  cur:=0;
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    if (x[i] = x0) and (y[i] = y0) then inc(cur);
    d[i]:=sqrt(sqr(x[i]-x0)+sqr(y[i]-y0));
  end;
  if cur >= k then ans:=0 else
  begin
    ll:=0; rr:=1e5;
    for it:=1 to 100 do
    begin
      mid:=(ll+rr)*0.5;
      for i:=1 to n do
        if mid > d[i] then prob[i]:=1
        else prob[i]:=exp(1-d[i]*d[i]/(mid*mid));
      for i:=0 to n do f[i]:=0;
      f[0]:=1;
      for i:=1 to n do
      begin
        g[0]:=f[0]*(1-prob[i]);
        for j:=1 to n do g[j]:=f[j-1]*prob[i]+f[j]*(1-prob[i]);
        for j:=0 to n do f[j]:=g[j];
      end;
      sum:=0;
      for j:=k to n do sum:=sum+f[j];
      if sum*1000 > 1000-need then rr:=mid
      else ll:=mid;
    end;
    ans:=(ll+rr)*0.5;
  end;
  writeln(ans:0:17);
  close(input);
  close(output);
end.