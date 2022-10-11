import java.io.*;
import java.util.*;
public class AMain {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new FileReader("input.txt")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int q = readInt();
		while(q-- > 0)	{
			pw.println((readInt()+1)%2);
		}
		pw.close();
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}