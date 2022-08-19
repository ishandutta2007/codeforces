{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  ans: extended;
  lev,loy: array [0..999] of longint;
  a,n,k,i: longint;

procedure rec(v,w:longint);
var
  s,t,i,z: longint;
  cur,prob: extended;
begin
  if v = n+1 then
  begin
    cur:=0;
    for t:=0 to 1 shl n-1 do
    begin
      prob:=1; z:=0; s:=0;
      for i:=1 to n do
        if t and (1 shl (i-1)) <> 0 then
        begin
          prob:=prob*loy[i]*0.01;
          inc(z);
        end else
        begin
          prob:=prob*(100-loy[i])*0.01;
          s:=s+lev[i];
        end;
      if 2*z > n then cur:=cur+prob
      else cur:=cur+prob*a/(a+s);
    end;
    if cur > ans then ans:=cur;
    exit;
  end;
  rec(v+1,w);
  if (w > 0) and (loy[v] < 100) then
  begin
    inc(loy[v],10);
    rec(v,w-1);
    dec(loy[v],10);
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,k,a);
  for i:=1 to n do read(lev[i],loy[i]);
  ans:=0;
  rec(1,k);
  writeln(ans:0:10);
  close(input);
  close(output);
end.