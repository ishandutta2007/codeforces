{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  w,pz,s,de,st,fin,ss,ff,pred,last,deg,num: array [0..500010] of longint;
  was: array [0..500010] of boolean;
  j,cc,kw,s1,s2,qq,tt,n,m,i,max,r,tmp,xx,yy,x,y,com: longint;

procedure add(x,v:longint);
begin
  while x <= kw do
  begin
    inc(s[x],v);
    x:=(x or (x-1))+1;
  end;
end;

function findsum(x:longint):longint;
var
  t: longint;
begin
  t:=0;
  while x > 0 do
  begin
    t:=t+s[x];
    x:=x and (x-1);
  end;
  findsum:=t;
end;

procedure rec(v,dep:longint);
var
  j: longint;
begin
  de[v]:=dep;
  st[v]:=cc;
  fin[v]:=kw;
  was[v]:=True;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      inc(kw);
      w[kw]:=num[j];
      rec(ff[j],dep+1);
    end;
    j:=pred[j];
  end;
end;

begin
  read(n);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    num[i+m]:=i;
    num[i]:=i;
  end;
  fillchar(deg,sizeof(deg),0);
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
    inc(deg[ss[i]]);
  end;
  max:=0; r:=0;
  for i:=1 to n do
    if deg[i] > max then
    begin
      max:=deg[i];
      r:=i;
    end;
  fillchar(was,sizeof(was),False);
  st[r]:=0; fin[r]:=0;
  was[r]:=True;
  de[r]:=0;
  kw:=0;
  j:=last[r];
  while j > 0 do
  begin
    inc(kw);
    w[kw]:=num[j];
    cc:=kw;
    rec(ff[j],1);
    j:=pred[j];
  end;
  fillchar(pz,sizeof(pz),0);
  for i:=1 to kw do pz[w[i]]:=i;
  fillchar(s,sizeof(s),0);
  read(tt);
  for qq:=1 to tt do
  begin
    read(com);
    if com = 1 then
    begin
      read(x);
      add(pz[x],-1);
    end else
    if com = 2 then
    begin
      read(x);
      add(pz[x],1);
    end else
    begin
      read(x,y);
      if st[x] = st[y] then
      begin
        xx:=fin[x]; yy:=fin[y];
        if xx > yy then begin tmp:=xx; xx:=yy; yy:=tmp; end;
        s1:=findsum(yy)-findsum(xx);
        if s1 = 0 then writeln(abs(de[y]-de[x]))
        else writeln(-1);
      end else
      begin
        s1:=findsum(fin[x])-findsum(st[x]-1);
        s2:=findsum(fin[y])-findsum(st[y]-1);
        if s1+s2 = 0 then writeln(de[x]+de[y])
        else writeln(-1);
      end;
    end;
  end;
end.