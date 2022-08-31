{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  s,g,was,win: array [0..100010] of longint;
  n,i,x,u,z,a1,ax: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(was,sizeof(was),0);
  s[0]:=0;
  for i:=1 to n do
  begin
    win[i]:=0;
    for x:=2 to i do
    begin
      u:=i-x*(x-1) div 2;
      if u < x then break;
      if u mod x = 0 then
      begin
        a1:=u div x;
        ax:=a1+x-1;
        z:=s[ax] xor s[a1-1];
        if (z = 0) and (win[i] = 0) then win[i]:=x;
        was[z]:=i;
      end;
    end;
    g[i]:=0;
    while was[g[i]] = i do inc(g[i]);
    s[i]:=s[i-1] xor g[i];
  end;
  if win[n] = 0 then writeln(-1)
  else writeln(win[n]);
  close(input);
  close(output);
end.