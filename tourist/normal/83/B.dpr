{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  kp,n,i,j: longint;
  first: boolean;
  p,t,a: array [0..1000010] of longint;
  ll,rr,mid,s,k,x: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,k);
  for i:=1 to n do read(a[i]);
  s:=0;
  for i:=1 to n do s:=s+a[i];
  if s < k then writeln(-1) else
  if s = k then writeln else
  begin
    ll:=0; rr:=round(1e9);
    while ll < rr do
    begin
      mid:=(ll+rr+1) div 2;
      x:=0;
      for i:=1 to n do
        if a[i] > mid then x:=x+mid
        else x:=x+a[i];
      if x <= k then ll:=mid
      else rr:=mid-1;
    end;
    mid:=ll;
    x:=0; kp:=0;
    for i:=1 to n do
      if a[i] > mid then
      begin
        inc(kp);
        p[kp]:=i;
        t[kp]:=a[i]-mid;
        x:=x+mid;
      end
      else x:=x+a[i];
    k:=k-x;
    for i:=1 to kp do
      if k = 0 then
      begin
        first:=True;
        for j:=i to kp do
        begin
          if not first then write(' ');
          first:=False;
          write(p[j]);
        end;
        for j:=1 to i-1 do
          if t[j] > 1 then
          begin
            if not first then write(' ');
            first:=False;
            write(p[j]);
          end;
        break;
      end
      else dec(k);
    writeln;
  end;
  close(input);
  close(output);
end.