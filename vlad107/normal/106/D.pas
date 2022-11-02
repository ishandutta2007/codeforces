var
  fu,fl,fr,fd:array[0..1111,0..1111]of longint;
  a:array[0..1111,0..1111]of char;
  x,y,xx,yy,t,q,n,m,i,j:longint;
  nch:array[0..500500]of char;
  nx:array[0..500500]of longint;
  res:array['A'..'Z']of boolean;
  nosol:boolean;
  ch:char;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  fillchar(fu,sizeof(fu),$FF);
  fillchar(fd,sizeof(fd),$FF);
  fillchar(fl,sizeof(fl),$FF);
  fillchar(fr,sizeof(fr),$FF);
  for i:=1 to n do 
    for j:=1 to m do begin
      fu[i][j]:=fu[i-1][j]+1;
      if (a[i][j]='#')then fu[i][j]:=-1;
      fl[i][j]:=fl[i][j-1]+1;
      if (a[i][j]='#')then fl[i][j]:=-1;
    end;
  for i:=n downto 1 do 
    for j:=m downto 1 do begin
      fr[i][j]:=fr[i][j+1]+1;
      if (a[i][j]='#')then fr[i][j]:=-1;
      fd[i][j]:=fd[i+1][j]+1;
      if (a[i][j]='#')then fd[i][j]:=-1;
    end;
  readln(t);
  for i:=1 to t do readln(nch[i],nx[i]);
  for i:=1 to n do
    for j:=1 to m do 
      if (a[i][j]in['A'..'Z'])then begin
        x:=i;y:=j;
        for q:=1 to t do begin
          xx:=x;yy:=y;
          case(nch[q])of
            'S':begin if (fd[x][y]<nx[q])then xx:=-10000;inc(xx,nx[q]);end;
            'N':begin if (fu[x][y]<nx[q])then xx:=-10000;dec(xx,nx[q]);end;
            'W':begin if (fl[x][y]<nx[q])then xx:=-10000;dec(yy,nx[q]);end;
            'E':begin if (fr[x][y]<nx[q])then xx:=-10000;inc(yy,nx[q]);end;
          end;
          if (xx<1)or(yy<1)or(xx>n)or(yy>m)or(a[xx][yy]='#')then begin
            x:=-1;break;
          end else begin
            x:=xx;y:=yy;
          end;
        end;
        if (xx<0)then continue;
        res[a[i][j]]:=true;
      end;
   nosol:=true;
   for ch:='A' to 'Z' do 
     if (res[ch])then begin
       write(ch);
       nosol:=false;
     end;
   if (nosol)then writeln('no solution')else writeln;
  close(output);close(input);
end.