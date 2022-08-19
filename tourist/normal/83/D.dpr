{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const co = 100000;
var
  d: array [0..co+10] of boolean;
  e: array [0..203333333] of byte;
  p: array [0..co+10] of longint;
  c,a,b,k,ll,rr,ans: int64;
  u,kp,i: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b,k);
  i:=2;
  while int64(i)*i <= k do
  begin
    if k mod i = 0 then
    begin
      writeln(0);
      halt;
    end;
    inc(i);
  end;
  ll:=(a+k-1) div k;
  rr:=b div k;
  ans:=0;
  if (ll <= 1) and (1 <= rr) then inc(ans);
  if ll < k then ll:=k;
  if ll > rr then writeln(ans) else
  begin
    fillchar(d,sizeof(d),True);
    for i:=2 to co do
      if d[i] then
      begin
        c:=i*i;
        if c > co then break;
        while c <= co do
        begin
          d[c]:=False;
          inc(c,i);
        end;
      end;
    kp:=0;
    for i:=2 to co do
      if d[i] and (i < k) then
      begin
        inc(kp);
        p[kp]:=i;
      end;
    for i:=ll shr 3 to rr shr 3 do e[i]:=0;
    for i:=1 to kp do
    begin
      u:=(ll+p[i]-1) div p[i]*p[i];
      while u <= rr do
      begin
        e[u shr 3]:=e[u shr 3] or (1 shl (u and 7));
        inc(u,p[i]);
      end;
    end;
    for i:=ll to rr do
      if e[i shr 3] and (1 shl (i and 7)) = 0 then inc(ans);
    writeln(ans);
  end;
  close(input);
  close(output);
end.