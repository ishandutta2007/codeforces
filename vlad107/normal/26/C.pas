{$r-,q-,s-,i-,o+}
const
  hx:array[1..4]of longint=(1,0,-1,0);
  hy:array[1..4]of longint=(0,1,0,-1);
var
  r:array[0..222,0..222]of char;
  w:array[0..222,0..222]of longint;
  n,m,a,b,c,i,j:longint;
  used:array['a'..'z']of boolean;
  ch:char;
  procedure check(x,y:longint);
    var
      cx,cy,q:longint;
    begin
      for q:=1 to 4 do begin
        cx:=x+hx[q];
        cy:=y+hy[q];
        if (r[cx][cy]='!')then continue;
        used[r[cx][cy]]:=true;
      end;
    end;
begin
  read(n,m,a,b,c);
  if (n and 1=1)and(m and 1=1)then begin
    writeln('IMPOSSIBLE');
    exit;
  end;
  i:=1;
  while (i<n)do begin
    j:=1;
    while (j<m)do begin
      w[i][j]:=3;
      dec(c);
      inc(j,2);
    end;
    inc(i,2);
  end;
  if (n and 1=1)then begin
    j:=1;
    while (j<m)do begin
      w[n][j]:=1;
      dec(a);
      inc(j,2);
    end;
    if (a<0)then begin
      writeln('IMPOSSIBLE');
      exit;
    end;
  end;
  if (m and 1=1)then begin
    i:=1;
    while (i<n)do begin
      w[i][m]:=2;
      dec(b);
      inc(i,2);
    end;
    if (b<0)then begin
      writeln('IMPOSSIBLE');
      exit;
    end;
  end;
    
  for i:=1 to n do 
    for j:=1 to m do 
      if (w[i][j]=3)and(c<0)then begin
        if (a>=2)then begin
          inc(c);
          dec(a,2);
          w[i][j]:=1;
          w[i+1][j]:=1;
          continue;
        end;
        if (b>=2)then begin
          inc(c);
          dec(b,2);
          w[i][j]:=2;
          w[i][j+1]:=2;
          continue;
        end;
        writeln('IMPOSSIBLE');
        exit;
      end;
  for i:=0 to n+1 do 
    for j:=0 to m+1 do r[i][j]:='!';
  for i:=1 to n do 
    for j:=1 to m do 
      if (w[i][j]=3)then begin
        fillchar(used,sizeof(used),false);
        check(i,j);
        check(i,j+1);
        check(i+1,j);
        check(i+1,j+1);
        ch:='a';
        while (used[ch])do ch:=chr(ord(ch)+1);
        r[i][j]:=ch;
        r[i][j+1]:=ch;
        r[i+1][j]:=ch;
        r[i+1][j+1]:=ch;
      end else
      if (w[i][j]=1)then begin
        fillchar(used,sizeof(used),false);
        check(i,j);
        check(i,j+1);
        ch:='a';
        while (used[ch])do ch:=chr(ord(ch)+1);
        r[i][j]:=ch;
        r[i][j+1]:=ch;
      end else 
      if (w[i][j]=2)then begin
        fillchar(used,sizeof(used),false);
        check(i,j);
        check(i+1,j);
        ch:='a';
        while (used[ch])do ch:=chr(ord(ch)+1);
        r[i][j]:=ch;
        r[i+1][j]:=ch;
      end;
  for i:=1 to n do begin
    for j:=1 to m do write(r[i][j]);
    writeln;
  end;
end.