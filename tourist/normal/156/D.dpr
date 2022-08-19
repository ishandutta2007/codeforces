{$R-,S-,Q-,I-,O+}
var
  n,m,md,i,ii,e,kt,j,ans: longint;
  t,ss,ff,pred,last,x: array [0..500010] of longint;
  was: array [0..500010] of boolean;
begin
  read(n,m,md);
  for i:=1 to m do read(ss[i],ff[i]);
  for i:=1 to m do
  begin
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  kt:=0;
  for ii:=1 to n do
    if not was[ii] then
    begin
      i:=1; e:=1;
      x[1]:=ii;
      was[ii]:=True;
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
          end;
          j:=pred[j];
        end;
        inc(i);
      end;
      inc(kt);
      t[kt]:=e;
    end;
  if kt = 1 then writeln(1 mod md) else
  begin
    ans:=1 mod md;
    for i:=1 to kt-2 do ans:=int64(ans)*n mod md;
    for i:=1 to kt do ans:=int64(ans)*t[i] mod md;
    writeln(ans);
  end;
end.