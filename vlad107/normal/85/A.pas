const
  hx:array[1..4]of longint=(1,0,-1,0);
  hy:array[1..4]of longint=(0,1,0,-1);
var
  n,i,j:longint;
  ch:char;
  used:array['a'..'z']of boolean;
  r:array[0..5,0..111]of char;
  w:array[0..5,0..111]of longint;
  procedure check(x,y:longint);
    var
      q,cx,cy:longint;
    begin
      for q:=1 to 4 do begin
        cx:=x+hx[q];
        cy:=y+hy[q];
        if (r[cx][cy]='!')then continue;
        used[r[cx][cy]]:=true;
      end;
    end;
begin
  read(n);
  if (n=1)then begin
    for i:=1 to 2 do writeln('a');
    for i:=1 to 2 do writeln('z');
    exit;
  end;
  if (n mod 2=0)then begin
    for i:=1 to 2 do begin
      j:=1;
      while (j<=n)do begin
        w[i][j]:=1;
        inc(j,2);
      end;
    end;
    for i:=3 to 4 do begin
      j:=2;
      while (j<n-1)do begin
        w[i][j]:=1;
        inc(j,2);
      end;
    end;
    w[3][1]:=2;
    w[3][n]:=2;
  end else begin
    for i:=1 to 2 do begin
      j:=1;
      while (j<n)do begin
        w[i][j]:=1;
        inc(j,2);
      end;
    end;
    w[1][n]:=2;
    for i:=3 to 4 do begin
      j:=2;
      while (j<=n)do begin
        w[i][j]:=1;
        inc(j,2);
      end;
    end;
    w[3][1]:=2;
  end;         
  for i:=0 to 5 do 
    for j:=0 to n+1 do r[i][j]:='!';
  for i:=1 to 4 do for j:=1 to n do 
    if (w[i][j]=1)then begin
      fillchar(used,sizeof(used),false);
      check(i,j);
      check(i,j+1);
      ch:='a';
      while (used[ch])do ch:=chr(ord(ch)+1);
      r[i][j]:=ch;
      r[i][j+1]:=ch;
    end else if (w[i][j]=2)then begin
      fillchar(used,sizeof(used),false);
      check(i,j);
      check(i+1,j);
      ch:='a';
      while (used[ch])do ch:=chr(ord(ch)+1);
      r[i][j]:=ch;
      r[i+1][j]:=ch;
    end;
  for i:=1 to 4 do begin
    for j:=1 to n do write(r[i][j]);
    writeln;
  end;
end.