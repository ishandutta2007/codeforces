{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  a: array [0..22,0..1111111] of longint;
  st: array [0..222222] of ansistring;
  cur,u,mask,len,n,i,j,ans: longint;
  f,s: array [0..222222] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  for i:=1 to n do readln(st[i]);
  len:=length(st[1]);
  s[1]:=0;
  for i:=2 to n do
  begin
    s[i]:=s[i-1]+len;
    for j:=len downto 1 do
      if Copy(st[i],1,j) = Copy(st[i-1],len-j+1,j) then
      begin
        s[i]:=s[i-1]+len-j;
        break;
      end;
  end;
  for i:=0 to len do
    for j:=0 to 1 shl i-1 do a[i,j]:=inf;
  ans:=s[n]+len;
  for i:=1 to n-1 do
  begin
    f[i]:=s[i]+2*len;
    mask:=0;
    for j:=0 to len do
    begin
      cur:=a[j,mask]+s[i]+len-j;
      if cur < f[i] then f[i]:=cur;
      if j = len then break;
      mask:=mask shl 1;
      if st[i+1,j+1] = '1' then inc(mask);
    end;
    cur:=f[i]+s[n]-s[i+1];
    if cur < ans then ans:=cur;
    u:=f[i]-s[i+1];
    mask:=0;
    for j:=0 to len do
    begin
      if u < a[j,mask] then a[j,mask]:=u;
      if j = len then break;
      if st[i,len-j] = '1' then mask:=mask+(1 shl j);
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.