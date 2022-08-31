{$R-,S-,Q-,I-,O+}
var
  n,a,d,i,t,v: longint;
  time,old,cur,z,ans: extended;
begin
  read(n,a,d);
  time:=sqrt(2*d/a);
  old:=0;
  for i:=1 to n do
  begin
    read(t,v);
    if time*a < v then ans:=t+time else
    begin
      cur:=v/a;
      z:=a*cur*cur/2;
      ans:=t+cur+(d-z)/v;
    end;
    if ans < old then ans:=old;
    writeln(ans:0:17);
    old:=ans;
  end;
end.