{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,m,tt,i,j,tmp,qq,a,b,ans: longint;
  d: int64;
  tot,x,y,r,xc,yc: array [0..10010] of longint;
  has: array [0..1010,0..1010] of byte;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,tt);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to m do read(r[i],xc[i],yc[i]);
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if r[i] < r[j] then
      begin
        tmp:=r[i]; r[i]:=r[j]; r[j]:=tmp;
        tmp:=xc[i]; xc[i]:=xc[j]; xc[j]:=tmp;
        tmp:=yc[i]; yc[i]:=yc[j]; yc[j]:=tmp;
      end;
  fillchar(has,sizeof(has),0);
  fillchar(tot,sizeof(tot),0);
  for i:=1 to n do
    for j:=1 to m do
    begin
      d:=int64(x[i]-xc[j])*(x[i]-xc[j])+int64(y[i]-yc[j])*(y[i]-yc[j]);
      has[i,j]:=Ord(d < int64(r[j])*r[j]);
      inc(tot[i],has[i,j]);
    end;
  for qq:=1 to tt do
  begin
    read(a,b);
    ans:=tot[a]+tot[b];
    for i:=1 to m do
      if has[a,i] <> has[b,i] then break else
      if has[a,i] = 1 then dec(ans,2);
    writeln(ans);
  end;
  close(input);
  close(output);
end.