{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,tmp,t,prob,time: longint;
  a: array [0..11111] of longint;
begin
{  assign(input,'in'); reset(input);
  assign(output,'out'); rewrite(output);}
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i] > a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      end;
  t:=-350;
  prob:=0; time:=0;
  for i:=1 to n do
  begin
    if t+a[i] > 360 then break;
    inc(prob);
    t:=t+a[i];
    if t > 0 then inc(time,t);
  end;
  writeln(prob,' ',time);
{  close(input);
  close(output);}
end.