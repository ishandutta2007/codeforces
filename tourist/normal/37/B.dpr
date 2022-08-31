{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  it,n,max,reg,i,cur,tot,ans,m,mn,km: longint;
  used: array [0..100010] of boolean;
  pow,dmg,a,b: array [0..100010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,max,reg);
  for i:=1 to n do read(pow[i],dmg[i]);
  fillchar(used,sizeof(used),False);
  cur:=max; tot:=0;
  ans:=-1; m:=0;
  for it:=0 to 10000 do
  begin
    cur:=cur-tot+reg;
    if cur <= 0 then
    begin
      ans:=it;
      break;
    end;
    if cur > max then cur:=max;
    mn:=0; km:=0;
    for i:=1 to n do
      if not used[i] and (cur*100 <= pow[i]*max) then
        if dmg[i] > mn then
        begin
          mn:=dmg[i];
          km:=i;
        end;
    if km > 0 then
    begin
      inc(m);
      a[m]:=it;
      b[m]:=km;
      inc(tot,mn);
      used[km]:=True;
    end;
  end;
  if ans = -1 then writeln('NO') else
  begin
    writeln('YES');
    writeln(ans,' ',m);
    for i:=1 to m do writeln(a[i],' ',b[i]);
  end;
  close(input);
  close(output);
end.