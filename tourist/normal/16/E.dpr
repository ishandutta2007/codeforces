{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,t,m,tot: longint;
  a: array [0..22,0..22] of extended;
  ans: array [0..22] of extended;
  b: array [0..22] of longint;
  f: array [0..1111111] of extended;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  fillchar(ans,sizeof(ans),0);
  fillchar(f,sizeof(f),0);
  f[1 shl n-1]:=1;
  for t:=1 shl n-1 downto 1 do
  begin
    m:=0;
    for i:=1 to n do
      if t and (1 shl (i-1)) <> 0 then
      begin
        inc(m);
        b[m]:=i;
      end;
    if m = 1 then ans[b[1]]:=f[t];
    tot:=m*(m-1) div 2;
    for i:=1 to m-1 do
      for j:=i+1 to m do
      begin
        f[t-(1 shl (b[i]-1))]:=f[t-(1 shl (b[i]-1))]+f[t]*a[b[j],b[i]]/tot;
        f[t-(1 shl (b[j]-1))]:=f[t-(1 shl (b[j]-1))]+f[t]*a[b[i],b[j]]/tot;
      end;
  end;
  for i:=1 to n-1 do write(ans[i]:0:17,' ');
  writeln(ans[n]:0:17);
  close(input);
  close(output);
end.