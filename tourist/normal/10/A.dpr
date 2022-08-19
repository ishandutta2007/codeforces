{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,p1,p2,p3,t1,t2,a,b,q,i,c,d: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,p1,p2,p3,t1,t2,a,b);
  q:=(b-a)*p1;
  for i:=2 to n do
  begin
    read(c,d);
    q:=q+(d-c)*p1;
    if c-b <= t1 then q:=q+(c-b)*p1 else
    begin
      inc(b,t1);
      q:=q+t1*p1;
      if c-b <= t2 then q:=q+(c-b)*p2 else
      begin
        inc(b,t2);
        q:=q+t2*p2+(c-b)*p3;
      end;
    end;
    a:=c;
    b:=d;
  end;
  writeln(q);
  close(input);
  close(output);
end.