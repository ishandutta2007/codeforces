{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b,c: array [0..110] of longint;
  nam: array [0..110] of ansistring;
  ss: ansistring;
  ch: char;
  n,x,y,p,q,i,j,tmp: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n);
  for i:=1 to n do readln(nam[i]);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  for i:=1 to n*(n-1) div 2 do
  begin
    read(ch);
    ss:='';
    while ch <> '-' do
    begin
      ss:=ss+ch;
      read(ch);
    end;
    x:=0;
    for j:=1 to n do
      if nam[j] = ss then x:=j;
    read(ch);
    ss:='';
    while ch <> ' ' do
    begin
      ss:=ss+ch;
      read(ch);
    end;
    y:=0;
    for j:=1 to n do
      if nam[j] = ss then y:=j;
    read(ch);
    p:=0;
    while ch <> ':' do
    begin
      p:=p*10+Ord(ch)-48;
      read(ch);
    end;
    readln(q);
    if p > q then inc(a[x],3) else
    if p < q then inc(a[y],3) else
    begin
      inc(a[x]);
      inc(a[y]);
    end;
    inc(b[x],p);
    inc(c[x],q);
    inc(b[y],q);
    inc(c[y],p);
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i] < a[j]) or (a[i] = a[j]) and (b[i]-c[i] < b[j]-c[j]) or
         (a[i] = a[j]) and (b[i]-c[i] = b[j]-c[j]) and (b[i] < b[j]) then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
        tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
        tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
        ss:=nam[i]; nam[i]:=nam[j]; nam[j]:=ss;
      end;
  for i:=1 to n shr 1-1 do
    for j:=i+1 to n shr 1 do
      if nam[i] > nam[j] then
      begin
        ss:=nam[i];
        nam[i]:=nam[j];
        nam[j]:=ss;
      end;
  for i:=1 to n shr 1 do writeln(nam[i]);
  close(input);
  close(output);
end.