{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  pv,pd,ans,a,num,ss,ff,dd,pred,last,x: array [0..20010] of longint;
  was: array [0..20010] of boolean;
  tmp,ii,e,day,n,i,m,j: longint;
  b: array [0..5010,0..5010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i],dd[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    dd[i+m]:=dd[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  i:=1; e:=1;
  x[1]:=1;
  was[1]:=True;
  pv[1]:=0;
  pd[1]:=0;
  while i <= e do
  begin
    j:=last[x[i]];
    while j > 0 do
    begin
      if not was[ff[j]] then
      begin
        inc(e);
        x[e]:=ff[j];
        was[x[e]]:=True;
        pv[x[e]]:=x[i];
        pd[x[e]]:=dd[j];
      end;
      j:=pred[j];
    end;
    inc(i);
  end;
  for i:=1 to n do num[i]:=i;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i] > a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
        tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      end;
  fillchar(b,sizeof(b),0);
  for ii:=1 to n do
  begin
    i:=num[ii];
    day:=0;
    while i > 1 do
    begin
      inc(day);
      if b[day,i] < pd[i] then
      begin
        inc(b[day,i]);
        i:=pv[i];
      end;
    end;
    ans[num[ii]]:=day;
  end;
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
  close(input);
  close(output);
end.