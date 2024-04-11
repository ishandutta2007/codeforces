{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  max,add: array [0..1111111] of int64;
  f,a,s: array [0..555555] of int64;
  last,pred,ss,ff,dd: array [0..555555] of longint;
  ft: int64;
  n,m,i,j: longint;

procedure modify(x,l,r,ll,rr:longint;v:int64);
var
  mid: longint;
  w: int64;
begin
  if (l >= ll) and (r <= rr) then add[x]:=add[x]+v else
  begin
    add[x+x]:=add[x+x]+add[x];
    add[x+x+1]:=add[x+x+1]+add[x];
    add[x]:=0;
    mid:=(l+r) shr 1;
    if ll <= mid then modify(x+x,l,mid,ll,rr,v);
    if rr > mid then modify(x+x+1,mid+1,r,ll,rr,v);
    max[x]:=max[x+x+1]+add[x+x+1];
    w:=max[x+x]+add[x+x];
    if w > max[x] then max[x]:=w;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to n do read(a[i]);
  fillchar(last,sizeof(last),0);
  for i:=1 to m do
  begin
    read(ss[i],ff[i],dd[i]);
    pred[i]:=last[ff[i]];
    last[ff[i]]:=i;
  end;
  s[0]:=0;
  for i:=1 to n do s[i]:=s[i-1]+a[i];
  fillchar(max,sizeof(max),0);
  fillchar(add,sizeof(add),0);
  f[0]:=0;
  for i:=1 to n do
  begin
    f[i]:=f[i-1];
    j:=last[i];
    while j > 0 do
    begin
      modify(1,0,n,0,ss[j]-1,dd[j]);
      j:=pred[j];
    end;
    ft:=max[1]+add[1]-s[i];
    if ft > f[i] then f[i]:=ft;
    modify(1,0,n,i,i,f[i]+s[i]);
  end;
  writeln(f[n]);
  close(input);
  close(output);
end.