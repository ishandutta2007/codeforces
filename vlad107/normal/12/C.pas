{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  n, m, i, j, q, max, min : longint;
  tt,k                    : array [1..1000] of longint;
  s                       : array [1..1000] of string;

  procedure qs(l, r : longint);
    var
      i, j, xx, tmp : longint;

    begin
      i := l; j := r;
      xx := k[(i+j) shr 1];
      while (i <= j) do begin
        while (xx > k[i]) do inc(i);
        while (xx < k[j]) do dec(j);
        if (i > j) then break;
        tmp := k[i]; k[i] := k[j]; k[j] := tmp;
        inc(i); dec(j);
      end;
      if (i < r) then qs(i, r);
      if (j > l) then qs(l, j);
    end;

  procedure qss(l, r : longint);
    var
      i, j : longint;
      xx, tmp : string;

    begin
      i := l; j := r;
      xx := s[(i+j) shr 1];
      while (i <= j) do begin
        while (xx > s[i]) do inc(i);
        while (xx < s[j]) do dec(j);
        if (i > j) then break;
        tmp := s[i]; s[i] := s[j]; s[j] := tmp;
        inc(i); dec(j);
      end;
      if (i < r) then qss(i, r);
      if (j > l) then qss(l, j);
    end;

  procedure qstt(l, r : longint);
    var
      xx, tmp, i, j : longint;

    begin
      i := l; j := r;
      xx := tt[(i+j) shr 1];
      while (i <= j) do begin
        while (xx > tt[i]) do inc(i);
        while (xx < tt[j]) do dec(j);
        if (i > j) then break;
        tmp := tt[i]; tt[i] := tt[j]; tt[j] := tmp;
        inc(i); dec(j);
      end;
      if (i < r) then qstt(i, r);
      if (j > l) then qstt(l, j);
    end;

begin
  readln(n,m);
  for i:=1 to n do read(k[i]);
  qs(1, n);
  readln;
  for i:=1 to m do readln(s[i]);
  qss(1, m);
  s[m+1] := '~';
  j := 1;
  q := 0;
  max := 0;
  min := 0;
  for i:=2 to m+1 do
    if (s[i] = s[i-1])
      then inc(j)
      else begin
        inc(q);
        tt[q] := j;
        j := 1;
      end;
  qstt(1, q);
  for i:=q downto 1 do begin
    inc(max, k[n-q+i]*tt[i]);
    inc(min, k[q-i+1]*tt[i]);
  end;
  writeln(min, ' ', max);
end.