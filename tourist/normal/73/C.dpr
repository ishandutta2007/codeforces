{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  c1,c2,ch: char;
  ans,t,nj,ft,j,p,k,nn,i,n: longint;
  s: ansistring;
  a: array [0..33,0..33] of longint;
  v: array [0..333] of longint;
  f: array [0..111,0..111,0..33] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(ch);
  while not (ch in ['a'..'z']) do read(ch);
  s:='';
  while ch in ['a'..'z'] do
  begin
    s:=s+ch;
    read(ch);
  end;
  read(k,nn);
  fillchar(a,sizeof(a),0);
  for i:=1 to nn do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    c1:=ch;
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    c2:=ch;
    read(a[Ord(c1)-96,Ord(c2)-96]);
  end;
  n:=length(s);
  for i:=1 to n do v[i]:=Ord(s[i])-96;
  fillchar(f,sizeof(f),210);
  f[0,0,0]:=0;
  for i:=0 to n-1 do
    for j:=0 to k do
      for p:=0 to 26 do
        if f[i,j,p] > -1e8 then
          for t:=1 to 26 do
          begin
            ft:=f[i,j,p]+a[p,t];
            nj:=j;
            if t <> v[i+1] then inc(nj);
            if nj <= k then
              if ft > f[i+1,nj,t] then
                f[i+1,nj,t]:=ft;
          end;
  ans:=-maxlongint;
  for j:=0 to k do
    for p:=1 to 26 do
      if f[n,j,p] > ans then ans:=f[n,j,p];
  writeln(ans);
  close(input);
  close(output);
end.