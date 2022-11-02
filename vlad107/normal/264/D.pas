{$r-,q-,s-,i-,o+}
const
  abc='RGB';

var
  x,y,i,j,la,lb:longint;
  f:array[0..1111,0..1111]of longint;
  first,last,a,b:array[0..1111111]of longint;
  tb:array[0..1111111,0..3,0..3]of longint;
  sa,sb:ansistring;
  ans:int64;

begin
  readln(sa);
  readln(sb);
  la:=length(sa);
  lb:=length(sb);
  for i:=1 to la do a[i]:=pos(sa[i],abc);
  for i:=1 to lb do b[i]:=pos(sb[i],abc);
  j:=1;
  for i:=1 to lb do begin
    for x:=1 to 3 do 
      for y:=1 to 3 do 
        tb[i][x][y]:=tb[i-1][x][y]+ord((x<>y)and(b[i-1]=x)and(b[i]=y));
  end;
  j:=1;
  for i:=1 to la do begin
    first[i]:=j;
    if (j<=lb)and(a[i]=b[j])then inc(j);
  end;
  j:=1;
  for i:=1 to la do begin
    while (j<=lb)and(a[i]<>b[j])do inc(j);
    if (j>lb)then j:=lb;
    last[i]:=j;
    inc(j);
  end;
  //for i:=1 to la do writeln(first[i],' ',last[i]);
  for i:=1 to la do begin
    ans:=ans+last[i]-first[i]+1;
    if (i>1)and(a[i]<>a[i-1])then ans:=ans-tb[last[i]][a[i],a[i-1]]+tb[first[i]-1][a[i],a[i-1]];
  end;
  {f[1][1]:=1;
  for i:=1 to la do
    for j:=1 to lb do begin
      if (f[i][j]=0)then continue;
      if (a[i]<>b[j])then begin
        if (i<la)then f[i+1][j]:=1;
        if (j<lb)then f[i][j+1]:=1;
      end else 
        if (i<la)and(j<lb)then f[i+1][j+1]:=1;
    end;
  write('* ');
  for i:=1 to lb do write(b[i],' ');
  writeln;
  for i:=1 to la do begin
    write(a[i],' ');
    for j:=1 to lb do write(f[i][j],' ');
    writeln;
  end;}
  writeln(ans);
end.