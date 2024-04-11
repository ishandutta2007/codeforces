{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ok: boolean;
  ss,a,b: ansistring;
  s: array [0..100010] of char;
  tmp: char;
  w: array [0..9] of boolean;
  n,na,nb,i,r,j: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(ss);
  readln(a);
  readln(b);
  n:=length(ss);
  na:=length(a);
  nb:=length(b);
  for i:=1 to n do s[i]:=ss[i];
  for r:=1 to 2 do
  begin
    i:=1; ok:=False;
    while i <= n-na+1 do
    begin
      ok:=True;
      for j:=i to i+na-1 do
        if s[j] <> a[j-i+1] then
        begin
          ok:=False;
          break;
        end;
      if ok then break;
      inc(i);
    end;
    if not ok then w[r]:=False else
    begin
      inc(i,na); ok:=False;
      while i <= n-nb+1 do
      begin
        ok:=True;
        for j:=i to i+nb-1 do
          if s[j] <> b[j-i+1] then
          begin
            ok:=False;
            break;
          end;
        if ok then break;
        inc(i);
      end;
      w[r]:=ok;
    end;
    for i:=1 to n shr 1 do
    begin
      tmp:=s[i];
      s[i]:=s[n-i+1];
      s[n-i+1]:=tmp;
    end;
  end;
  if w[1] and w[2] then writeln('both') else
  if w[1] then writeln('forward') else
  if w[2] then writeln('backward')
  else writeln('fantasy');
  close(input);
  close(output);
end.