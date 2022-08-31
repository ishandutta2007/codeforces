{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  ans: int64;
  n,m,i,tx,ty: longint;
  was: array [0..400010] of boolean;
  x,y,ss,ff,pred,last,sx,sy,sz: array [0..400010] of longint;

procedure rec(v:longint);
var
  j: longint;
begin
  was[v]:=True;
  sx[v]:=x[v];
  sy[v]:=y[v];
  sz[v]:=1;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      rec(ff[j]);
      ans:=ans+int64(sx[ff[j]])*y[v]*sz[ff[j]];
      inc(sx[v],sx[ff[j]]);
      inc(sy[v],sy[ff[j]]);
      inc(sz[v],sz[ff[j]]);
    end;
    j:=pred[j];
  end;
  ans:=ans+int64(tx-sx[v])*y[v]*(n-sz[v]);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  tx:=0; ty:=0;
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    inc(tx,x[i]);
    inc(ty,y[i]);
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  ans:=0;
  rec(1);
  writeln(ans/tx/ty:0:17);
  close(input);
  close(output);
end.