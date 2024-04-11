{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 10000000}
var
  n,i,j,kw,ii,kr,q: longint;
  ch: char;
  g,t: array [0..5010,0..5010] of boolean;
  was: array [0..5010] of boolean;
  r,w: array [0..5010] of longint;

procedure rec(v:longint);
var
  j: longint;
begin
  was[v]:=True;
  for j:=1 to n do
    if not was[j] and t[v,j] then rec(j);
  inc(kw);
  w[kw]:=v;
end;

procedure rec2(v:longint);
var
  j: longint;
begin
  inc(kr);
  r[kr]:=v;
  was[v]:=True;
  for j:=1 to n do
    if not was[j] and g[v,j] then rec2(j);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      read(ch);
      g[i,j]:=ch = '1';
      t[j,i]:=g[i,j];
    end;
    readln;
  end;
  fillchar(was,sizeof(was),False);
  kw:=0;
  for i:=1 to n do
    if not was[i] then rec(i);
  fillchar(was,sizeof(was),False);
  for ii:=kw downto 1 do
  begin
    i:=w[ii];
    if not was[i] then
    begin
      kr:=0;
      rec2(i);
      if kr >= 3 then
      begin
        q:=r[1];
        for i:=2 to kr do
          if g[q,r[i]] then
            for j:=2 to kr do
              if t[q,r[j]] then
                if g[r[i],r[j]] then
                begin
                  writeln(q,' ',r[i],' ',r[j]);
                  halt;
                end;
      end;
    end;
  end;
  writeln(-1);
  close(input);
  close(output);
end.