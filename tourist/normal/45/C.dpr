{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const inf = 1000000;
var
  hh2,hh,n,i,ka,kh: longint;
  ch: char;
  c: array [0..400010] of char;
  good: array [0..400010] of boolean;
  ne,pr,g,h,h2,a,b: array [0..400010] of longint;
  h3,u: array [0..400010] of int64;

procedure up(t:longint);
var
  tmp: longint;
  tt: int64;
begin
  while (t > 1) and (h3[t] < h3[t shr 1]) do
  begin
    tmp:=h[t]; h[t]:=h[t shr 1]; h[t shr 1]:=tmp;
    tmp:=h2[t]; h2[t]:=h2[t shr 1]; h2[t shr 1]:=tmp;
    tt:=h3[t]; h3[t]:=h3[t shr 1]; h3[t shr 1]:=tt;
    t:=t shr 1;
  end;
end;

procedure down(t:longint);
var
  tt: int64;
  w,tmp: longint;
begin
  while True do
  begin
    w:=t shl 1;
    if w > kh then break;
    if w < kh then
      if h3[w+1] < h3[w] then inc(w);
    if h3[t] > h3[w] then
    begin
      tmp:=h[t]; h[t]:=h[w]; h[w]:=tmp;
      tmp:=h2[t]; h2[t]:=h2[w]; h2[w]:=tmp;
      tt:=h3[t]; h3[t]:=h3[w]; h3[w]:=tt;
      t:=w;
    end
    else break;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(ch);
    while not (ch in ['B','G']) do read(ch);
    c[i]:=ch;
  end;
  for i:=1 to n do read(g[i]);
  for i:=0 to n+1 do
  begin
    pr[i]:=i-1;
    ne[i]:=i+1;
    good[i]:=True;
  end;
  for i:=1 to n-1 do u[i]:=int64(abs(g[i]-g[i+1]))*inf+i;
  kh:=0;
  for i:=1 to n-1 do
    if c[i] <> c[i+1] then
    begin
      inc(kh);
      h[kh]:=i;
      h2[kh]:=i+1;
      h3[kh]:=u[i];
      up(kh);
    end;
  ka:=0;
  while kh > 0 do
  begin
    hh:=h[1];
    hh2:=h2[1];
    h[1]:=h[kh];
    h2[1]:=h2[kh];
    h3[1]:=h3[kh];
    dec(kh);
    down(1);
    if good[hh] and good[ne[hh]] and (ne[hh] <= n) and (c[hh] <> c[ne[hh]]) and (ne[hh] = hh2) then
    begin
      inc(ka);
      a[ka]:=hh;
      b[ka]:=ne[hh];
      good[a[ka]]:=False;
      good[b[ka]]:=False;
      if (pr[a[ka]] > 0) and (ne[b[ka]] <= n) and (c[pr[a[ka]]] <> c[ne[b[ka]]]) then
      begin
        u[pr[a[ka]]]:=int64(abs(g[pr[a[ka]]]-g[ne[b[ka]]]))*inf+pr[a[ka]];
        inc(kh);
        h[kh]:=pr[a[ka]];
        h2[kh]:=ne[b[ka]];
        h3[kh]:=u[pr[a[ka]]];
        up(kh);
      end;
      pr[ne[a[ka]]]:=pr[a[ka]];
      ne[pr[a[ka]]]:=ne[a[ka]];
      pr[ne[b[ka]]]:=pr[b[ka]];
      ne[pr[b[ka]]]:=ne[b[ka]];
    end;
  end;
  writeln(ka);
  for i:=1 to ka do writeln(a[i],' ',b[i]);
  close(input);
  close(output);
end.