{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const seg: array [0..9] of string = ('1111110','0010100','1011011','1010111','0110101',
                                     '1100111','1101111','1010100','1111111','1110111');
var
  i,j,k,n,ki,kj,cur,ncur: longint;
  p: array [0..9,0..9] of longint;
  g,s,a: array [0..400010] of longint;
  st: ansistring;
begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  for i:=0 to 9 do
    for j:=0 to 9 do
    begin
      p[i,j]:=0;
      for k:=1 to 7 do
        if (seg[i,k] = '1') and (seg[j,k] = '1') then inc(p[i,j]);
    end;
  readln(st);
  n:=length(st) shr 1;
  for i:=1 to 2*n do a[i]:=Ord(st[i])-48;
  s[0]:=0;
  for i:=1 to n do s[i]:=s[i-1]+p[a[i],a[i+n]];
  g[0]:=0;
  for i:=1 to n do g[i]:=g[i-1]+p[a[i],a[i]];
  ki:=0; kj:=0;
  for i:=2*n downto 1 do
  begin
    for j:=a[i]+1 to 9 do
    begin
      if i > n then cur:=s[i-1-n]+p[j,a[i-n]]+g[n]-g[i-n]
      else cur:=g[i-1]+p[j,j]+7*(n-i);
      if cur > s[n] then
      begin
        ki:=i; kj:=j;
        break;
      end;
    end;
    if ki > 0 then break;
  end;
  if ki = 0 then writeln(-1) else
  begin
    a[ki]:=kj;
    for i:=ki+1 to 2*n do a[i]:=8;
    cur:=0;
    for i:=1 to n do cur:=cur+p[a[i],a[i+n]];
    for i:=ki+1 to 2*n do
      for j:=0 to 9 do
      begin
        if i <= n then ncur:=cur-p[a[i],a[i+n]]+p[j,a[i+n]]
        else ncur:=cur-p[a[i],a[i-n]]+p[j,a[i-n]];
        if ncur > s[n] then
        begin
          a[i]:=j;
          cur:=ncur;
          break;
        end;
      end;
    for i:=1 to 2*n do write(a[i]);
    writeln;
  end;
  close(input);
  close(output);
end.