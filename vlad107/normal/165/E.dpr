const
  maxa=1 shl 22-1;
  
var
  n,i,j,x:longint;
  a,f:array[0..maxa]of longint;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(F),$FF);
  for i:=1 to n do f[a[i]]:=a[i];
  for i:=0 to maxa do
    if (F[i]=-1)then begin
      x:=1;
      for j:=0 to 30 do begin
        if (x>i)then break;
        if (i and x<>0)and(f[i-x]<>-1)then begin
          f[i]:=f[i-x];
          break;
        end;
        x:=x+x;
      end;
    end;
  for i:=1 to n do write(f[maxa-a[i]],' ');
  close(output);close(input);
end.