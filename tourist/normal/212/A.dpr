{$R-,S-,Q-,I-,O+}
{$M 50000000}
const maxm = 100010; maxn = 10010;
var
  e1,e2,ans,qq,tt,m,mm,fin,i,qs,qf,n1,n2,t: longint;
  res,ss,ff,c,f,obr,pred: array [0..maxm] of longint;
  min,deg,st,last,x,d: array [0..maxn] of longint;

procedure add(x,y,z,xx,yy:longint);
begin
  inc(m);
  ss[m]:=x;
  ff[m]:=y;
  c[m]:=z;
  f[m]:=xx;
  obr[m]:=yy;
  pred[m]:=last[x];
  last[x]:=m;
end;

function expath():boolean;
var
  i,e,j: longint;
begin
  for i:=0 to fin do d[i]:=-1;
  i:=1; e:=1;
  x[1]:=0;
  d[0]:=0;
  while i <= e do
  begin
    j:=last[x[i]];
    while j > 0 do
    begin
      if (c[j] > f[j]) and (d[ff[j]] = -1) then
      begin
        inc(e);
        x[e]:=ff[j];
        d[x[e]]:=d[x[i]]+1;
        if x[e] = fin then break;
      end;
      j:=pred[j];
    end;
    inc(i);
  end;
  expath:=d[fin] <> -1;
end;

function rec(v,w:longint):longint;
var
  t,j,r,ww: longint;
begin
  if v = fin then
  begin
    rec:=w;
    exit;
  end;
  r:=0;
  j:=last[v];
  while j > 0 do
  begin
    if (c[j] > f[j]) and (d[ff[j]] = d[v]+1) then
    begin
      ww:=c[j]-f[j];
      if w-r < ww then ww:=w-r;
      t:=rec(ff[j],ww);
      if t > 0 then
      begin
        inc(f[j],t);
        if obr[j] <> 0 then dec(f[obr[j]],t);
        inc(r,t);
        if r = w then break;
      end;
    end;
    last[v]:=pred[j];
    j:=pred[j];
  end;
  rec:=r;
end;

begin
  read(n1,n2,mm,tt);
  fin:=n1+n2+3;
  for i:=1 to n1 do add(n1+n2+1,i,0,0,0);
  for i:=n1+1 to n1+n2 do add(i,n1+n2+2,0,0,0);
  fillchar(deg,sizeof(deg),0);
  for i:=1 to mm do
  begin
    read(qs,qf);
    add(qs,qf+n1,1,0,m+2);
    add(qf+n1,qs,0,0,m);
    inc(deg[qs]);
    inc(deg[qf+n1]);
    res[i]:=0;
  end;
  ans:=0;
  for i:=1 to n1+n2 do
    if deg[i] mod tt > 0 then inc(ans);
  for i:=1 to n1 do add(0,i,0,0,0);
  for i:=n1+1 to n1+n2 do add(i,fin,0,0,0);
  add(n1+n2+1,fin,0,0,0);
  e1:=m;
  add(0,n1+n2+2,0,0,0);
  e2:=m;
  add(n1+n2+2,n1+n2+1,1000000000,0,m+2);
  add(n1+n2+1,n1+n2+2,0,0,m);
  for i:=1 to n1 do
  begin
    add(i,n1+n2+1,0,0,i);
    obr[i]:=m;
  end;
  for i:=n1+1 to n1+n2 do
  begin
    add(n1+n2+2,i,0,0,i);
    obr[i]:=m;
  end;
  fillchar(last,sizeof(last),0);
  for i:=m downto 1 do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  for qq:=1 to tt do
  begin
    fillchar(f,sizeof(f),0);
    c[e1]:=0; c[e2]:=0;
    for i:=1 to n1+n2 do
    begin
      min[i]:=deg[i] div (tt-qq+1);
      c[n1+n2+2*mm+i]:=min[i];
      if i <= n1 then inc(c[e1],min[i])
      else inc(c[e2],min[i]);
      if deg[i] mod (tt-qq+1) > 0 then c[i]:=1
      else c[i]:=0;
    end;
    for i:=0 to fin do st[i]:=last[i];
    while expath() do
    begin
      t:=rec(0,1000000000);
      for i:=0 to fin do last[i]:=st[i];
    end;
    for i:=1 to m do
      if ((ss[i] = 0) or (ff[i] = fin)) and (c[i] > f[i]) then
      begin
        writeln('botva');
        while true do;
        halt;
      end;
    for i:=n1+n2+1 to n1+n2+2*mm do
      if f[i] = 1 then
      begin
        res[(i-n1-n2) div 2+1]:=qq;
        c[i]:=0;
        dec(deg[ss[i]]);
        dec(deg[ff[i]]);
      end;
  end;
  writeln(ans);
  for i:=1 to mm-1 do write(res[i],' ');
  writeln(res[mm]);
end.