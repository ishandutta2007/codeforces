const fi = '';
      fo = '';
      maxN = 100;
var n, d, l, cn, cp: longint;
    an, ap: array [1..maxN] of longint;

procedure Work;
var jn, jp, i, cn, cp, cur: longint;
begin
 cn:=n div 2; cp:=n - cn;
 for i:=1 to cn do an[i]:=1;
 for i:=1 to cp do ap[i]:=1;
 cur:=cp-cn;

 jn:=1; jp:=1;
 while cur <> d do
  begin
   if cur < d then
    begin
      while (ap[jp] = l) and (jp <= cp) do inc(jp);
      if jp > cp then
       begin
        writeln(-1);
        exit;
       end;
      inc(ap[jp]); inc(cur);
    end
   else
    begin
      while (an[jn] = l) and (jn <= cn) do inc(jn);
      if jn > cn then
       begin
        writeln(-1);
        exit;
       end;
      inc(an[jn]); dec(cur);
    end
  end;

 for i:=1 to cn do write(ap[i], ' ', an[i], ' ');
 if cp > cn then write(ap[i]);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(n, d, l);
 Work;

 close(input); close(output);
end.