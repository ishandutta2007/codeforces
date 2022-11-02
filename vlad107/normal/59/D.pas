{$r-,q-,s-,i-,o+}
var
  tmp,q,n,i,j,x,nx:longint;
  w:array[0..100500,0..4]of longint;
  r:array[0..4,0..500500]of longint;
  k:array[0..4]of longint;
  a,b:array[0..500500]of longint;
  procedure qs(ll,rr:longint);
    var
      i,j,xx:longint;
    begin
      i:=ll;j:=rr;
      xx:=r[q,(i+j)shr 1];
      while (i<=j)do begin
        while (xx>r[q][i])do inc(i);
        while (xx<r[q][j])do dec(j);
        if (i>j)then break;
        tmp:=r[q][i];r[q][i]:=r[q][j];r[q][j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<rr)then qs(i,rr);
      if (j>ll)then qs(ll,j);
    end;
begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(n);
  for i:=1 to 3*n do begin
    read(a[i]);
    b[a[i]]:=i;
  end;
  for i:=1 to n do 
    for j:=1 to 3 do read(w[i][j]);
  read(x);
  for i:=1 to n do begin
    for q:=1 to 2 do 
      for j:=1 to 2 do 
        if (b[w[i][j]]>b[w[i][j+1]])then begin
          tmp:=w[i][j];w[i][j]:=w[i][j+1];w[i][j+1]:=tmp;
        end;
    if (w[i][2]=x)or(w[i][3]=x)then begin
      for j:=1 to 3*n do 
        if (j<>x)then write(j,' ');
      writeln;
      exit;
    end;
    if (w[i][1]=x)then begin
      nx:=i;
      break;
    end;
  end;
  k[1]:=2;
  k[2]:=0;
  r[1][1]:=w[nx][2];
  r[1][2]:=w[nx][3];
  for i:=1 to nx-1 do 
    for j:=1 to 3 do 
      if (w[i][j]<w[nx][3])or(w[i][j]<w[nx][2])then begin
        inc(k[1]);
        r[1][k[1]]:=w[i][j];
      end else begin
        inc(k[2]);
        r[2][k[2]]:=w[i][j];
      end;
  for i:=nx+1 to n do for j:=1 to 3 do begin
    inc(k[2]);
    r[2][k[2]]:=w[i][j];
  end;
  q:=1;qs(1,k[1]);
  q:=2;qs(1,k[2]);
//  writeln(k[1],' ',k[2]);
  for i:=1 to 2 do 
    for j:=1 to k[i]do write(r[i][j],' ');
  writeln;
end.