{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  q,u,j,n,s,i: longint;
  a: array [0..6010] of longint;

function prime(x:longint):boolean;
var
  i: longint;
begin
  for i:=2 to x-1 do
    if i*i > x then break else
    if x mod i = 0 then
    begin
      prime:=False;
      exit;
    end;
  prime:=x > 1;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  s:=n*(n+1) div 2;
  for i:=1 to n do a[i]:=1;
  if not prime(s) then
    if prime(s-2) then a[2]:=2 else
    begin
      if s and 1 = 1 then
        for i:=n downto 1 do
          if prime(i) then
          begin
            s:=s-i;
            a[i]:=3;
            break;
          end;
      for q:=1 to s-1 do
        if prime(q) and prime(s-q) then
        begin
          u:=q;
          for j:=n downto 1 do
            if (u >= j) and (a[j] = 1) then
            begin
              dec(u,j);
              a[j]:=2;
            end;
          break;
        end;
    end;
  for i:=1 to n-1 do write(a[i],' ');
  writeln(a[n]);
  close(input);
  close(output);
end.