var
  was:array[0..10]of boolean;
  d,p:array[0..10]of longint;
  a,r:array[0..100,0..100]of char;
  nr,mr,n,m,i,j:longint;
  t,s:array[0..10]of string;
  found:boolean;
  procedure rec(x:longint);
    var
      i,j:longint;
    begin
      if (x>6)then begin
        for i:=1 to 6 do t[i]:=s[p[i]];
        for i:=1 to 6 do d[i]:=length(t[i]);
        if (d[1]+d[3]-1<>d[2])or(d[4]+d[6]-1<>d[5])then exit;
        m:=d[5];
        n:=d[2];
        for i:=1 to n do for j:=1 to m do a[i][j]:='.';
        for i:=1 to d[4] do a[1][i]:=t[4][i];
        for i:=1 to d[5] do a[d[1]][i]:=t[5][i];
        for i:=d[4] to d[4]+d[6]-1 do a[d[2]][i]:=t[6][i-d[4]+1];
        
        for i:=1 to d[1] do begin
          if (a[i][1]<>'.')and(a[i][1]<>t[1][i])then exit;
          a[i][1]:=t[1][i];
        end;
        for i:=1 to d[2] do begin
          if (a[i][d[4]]<>'.')and(a[i][d[4]]<>t[2][i])then exit;
          a[i][d[4]]:=t[2][i];
        end;
        for i:=d[1] to d[1]+d[3]-1 do begin
          if (a[i][d[5]]<>'.')and(a[i][d[5]]<>t[3][i-d[1]+1])then exit;
          a[i][d[5]]:=t[3][i-d[1]+1];
        end;
        found:=false;
        for i:=1 to n do begin
          j:=1;
          while (a[i][j]=r[i][j])and(j<=mr)and(j<=m)do inc(j);
          if (j>mr)or(j>m)then begin
            if (m=mr)then continue;
            if (m>mr)then exit;
            break;
          end;
          if (a[i][j]>r[i][j])then exit;
          break;
        end;
        nr:=n;mr:=m;
        for i:=1 to n do for j:=1 to m do r[i][j]:=a[i][j];
        exit;
      end;
      for i:=1 to 6 do begin
        if (was[i])then continue;
        was[i]:=true;
        p[x]:=i;
        rec(x+1);
        p[x]:=0;
        was[i]:=false;
      end;
    end;
begin
  for i:=1 to 6 do readln(s[i]);
  fillchar(was,sizeof(was),false);
  r[1][1]:=#255;
  nr:=1;mr:=1;
  rec(1);
  if (r[1][1]=#255)then begin
    writeln('Impossible');
    exit;
  end;
  for i:=1 to nr do begin
    for j:=1 to mr do write(r[i][j]);
    writeln;
  end;
end.