{$R-,S-,Q-,I-,O+}
var
  n,m,ii,i,kr,j,e,max: longint;
  cg,cs,cost,ans: int64;
  ss,ff,dg,ds: array [0..50010] of longint;
  x,km,sr,fr,dr,pred,last: array [0..410] of longint;
  was: array [0..410] of boolean;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=dg[l+random(r-l+1)];
  repeat
    while dg[i] < x do inc(i);
    while x < dg[j] do dec(j);
    if i <= j then
    begin
      tmp:=ss[i]; ss[i]:=ss[j]; ss[j]:=tmp;
      tmp:=ff[i]; ff[i]:=ff[j]; ff[j]:=tmp;
      tmp:=dg[i]; dg[i]:=dg[j]; dg[j]:=tmp;
      tmp:=ds[i]; ds[i]:=ds[j]; ds[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randseed:=8753;
  read(n,m,cg,cs);
  for i:=1 to m do read(ss[i],ff[i],dg[i],ds[i]);
  Sort(1,m);
  ds[0]:=0; kr:=0;
  ans:=-1;
  for ii:=1 to m do
  begin
    for i:=1 to kr do
    begin
      sr[i+kr]:=fr[i];
      fr[i+kr]:=sr[i];
      dr[i+kr]:=dr[i];
    end;
    fillchar(last,sizeof(last),0);
    for i:=1 to kr+kr do
    begin
      pred[i]:=last[sr[i]];
      last[sr[i]]:=i;
    end;
    fillchar(was,sizeof(was),False);
    fillchar(km,sizeof(km),0);
    i:=1; e:=1;
    x[1]:=ss[ii];
    was[x[1]]:=True;
    while i <= e do
    begin
      j:=last[x[i]];
      while j > 0 do
      begin
        if not was[fr[j]] then
        begin
          inc(e);
          x[e]:=fr[j];
          was[x[e]]:=True;
          km[x[e]]:=km[x[i]];
          if dr[j] > dr[km[x[e]]] then
            km[x[e]]:=j;
        end;
        j:=pred[j];
      end;
      inc(i);
    end;
    if not was[ff[ii]] then
    begin
      inc(kr);
      sr[kr]:=ss[ii];
      fr[kr]:=ff[ii];
      dr[kr]:=ds[ii];
    end else
    begin
      j:=km[ff[ii]];
      if j > kr then dec(j,kr);
      if dr[j] > ds[ii] then
      begin
        sr[j]:=ss[ii];
        fr[j]:=ff[ii];
        dr[j]:=ds[ii];
      end;
    end;
    if kr = n-1 then
    begin
      max:=0;
      for i:=1 to kr do
        if dr[i] > max then max:=dr[i];
      cost:=cg*dg[ii]+cs*max;
      if (ans = -1) or (ans > cost) then ans:=cost;
    end;
  end;
  writeln(ans);
end.