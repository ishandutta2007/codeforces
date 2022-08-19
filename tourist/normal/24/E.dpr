{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,i,it: longint;
  ok: boolean;
  ll,rr,t,c,u: extended;
  x,v: array [0..500010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],v[i]);
  ll:=0; rr:=1e9+20;
  for it:=1 to 100 do
  begin
    t:=(ll+rr)*0.5;
    c:=-1e50; ok:=False;
    for i:=1 to n do
      if v[i] > 0 then
      begin
        u:=x[i]+t*v[i];
        if u > c then c:=u;
      end else
      begin
        u:=x[i]+t*v[i];
        if u <= c then
        begin
          ok:=True;
          break;
        end;
      end;
    if ok then rr:=t
    else ll:=t;
  end;
  if rr > 1e9+10 then writeln(-1)
  else writeln((ll+rr)*0.5:0:11);
  close(input);
  close(output);
end.