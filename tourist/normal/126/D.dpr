{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  tt,qqq,q,w,u,qq,ww,ee,m,i: longint;
  n: int64;
  ch: char;
  f: array [0..99] of int64;
  a: array [0..99] of longint;
  g: array [0..99,0..3,0..3] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(tt);
  for qqq:=1 to tt do
  begin
    read(ch);
    while not (ch in ['0'..'9']) do read(ch);
    n:=0;
    while ch in ['0'..'9'] do
    begin
      n:=n*10+Ord(ch)-48;
      read(ch);
    end;
    f[0]:=1;
    f[1]:=1;
    i:=2;
    while f[i-1] <= n do
    begin
      f[i]:=f[i-1]+f[i-2];
      inc(i);
    end;
    m:=i-1;
    for i:=m downto 1 do
      if n >= f[i] then
      begin
        a[i]:=1;
        n:=n-f[i];
      end
      else a[i]:=0;
    fillchar(g,sizeof(g),0);
    g[m,0,0]:=1;
    for i:=m downto 1 do
      for q:=0 to 2 do
        for w:=0 to 2 do
          if g[i,q,w] > 0 then
          begin
            qq:=q+a[i];
            for u:=qq-1 to qq do
              if u >= 0 then
              begin
                ww:=w+u; ee:=u;
                if (ww <= 2) and (ee <= 2) then
                  g[i-1,ww,ee]:=g[i-1,ww,ee]+g[i,q,w];
              end;
          end;
    writeln(g[0,0,0]);
  end;
  close(input);
  close(output);
end.