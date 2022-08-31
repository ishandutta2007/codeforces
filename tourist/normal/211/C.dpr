{$R-,S-,Q-,I-,O+}
{$M 50000000}
type TLong = array [0..511] of longint;
var
  s: ansistring;
  n,s1,s2,i,j,k,v,p: longint;
  one,ans: TLong;
  f: array [0..111,0..5] of TLong;

procedure add(var a,b:TLong);
var
  mx,i,v: longint;
begin
  mx:=a[0];
  if b[0] > mx then mx:=b[0];
  v:=0;
  for i:=1 to mx+1 do
  begin
    inc(a[i],b[i]+v);
    if a[i] > 9 then
    begin
      dec(a[i],10);
      v:=1;
    end
    else v:=0;
  end;
  a[0]:=mx+1;
  while (a[0] > 0) and (a[a[0]] = 0) do dec(a[0]);
end;

begin
  readln(s);
  n:=length(s);
  fillchar(one,sizeof(one),0);
  one[0]:=1; one[1]:=1;
  fillchar(ans,sizeof(ans),0);
  for s1:=0 to 1 do
    for s2:=0 to 1 do
    begin
      fillchar(f,sizeof(f),0);
      if (s1 = 1) and (s2 = 0) then f[2,2]:=one
      else f[2,s2]:=one;
      for i:=2 to n-1 do
        for j:=0 to 2 do
          for k:=0 to 1 do
          begin
            if (j = 1) and (k = 0) then p:=0 else
            if j = 2 then p:=1
            else p:=j;
            if (p = 0) and (s[i] = 'A') or (p = 1) and (s[i] = 'B') then continue;
            if (j = 1) and (k = 0) then v:=2
            else v:=k;
            add(f[i+1,v],f[i,j]);
          end;
      for j:=0 to 2 do
      begin
        if j = 2 then p:=1
        else p:=j;
        v:=s1;
        if (s1 = 1) and (s2 = 0) then v:=1-v;
        if (j = 1) and (s1 = 0) then
        begin
          p:=1-p;
          v:=1-v;
        end;
        if (p = 0) and (s[n] = 'A') or (p = 1) and (s[n] = 'B') then continue;
        if (v = 0) and (s[1] = 'A') or (v = 1) and (s[1] = 'B') then continue;
        add(ans,f[n,j]);
      end;
    end;
  for i:=ans[0] downto 1 do write(ans[i]);
  if ans[0] = 0 then write(0);
  writeln;
end.