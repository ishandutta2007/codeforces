var
  i,j,x,y,k,n,m:longint;
  ans:int64;
  ki,kj:array['a'..'z']of longint;
  ch:char;
  c1,c2:array[0..444]of char;
  kt:array[0..444]of longint;
  f:array[0..444,0..444]of longint;
  a:array[0..444,0..444]of char;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(n,m,k);
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i][j]);
      f[i][j]:=ord(a[i][j]='a');
    end;
    readln;
  end;
  for i:=1 to n do 
    for j:=1 to m do f[i][j]:=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+f[i][j];
  ans:=0;
  for x:=1 to n do 
    for y:=x+1 to n do begin
      for i:=1 to m do begin
        kt[i]:=f[y][i]-f[x-1][i];
        c1[i]:=a[x][i];
        c2[i]:=a[y][i];
      end;
      for ch:='a' to 'z' do begin ki[ch]:=0;kj[ch]:=0;end;
      j:=1;
      for i:=1 to m do begin
        while (j<i)and(kt[i]-kt[j-1]>k)do begin
          if (c1[j]=c2[j])then inc(kj[c1[j]]);
          inc(j);
        end;
        if (j<i)and(c1[i]=c2[i])then ans:=ans+ki[c1[i]]-kj[c1[i]];
        if (c1[i]=c2[i])then inc(ki[c1[i]]);
      end;
    end;
  writeln(ans);
end.